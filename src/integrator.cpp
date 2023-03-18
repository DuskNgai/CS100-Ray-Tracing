/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of the integrator, which calculate the radiance of a ray.
 *
 * Copyright (C) 2023
 * Author: Haizhao Dai
 * Email: daihzh@shanghaitech.edu.cn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "integrator.h"

#include <atomic>
#include <cstdio>
#include <thread>
#include <vector>

CS100_RAY_TRACING_NAMESPACE_BEGIN

Integrator::Integrator(uint32_t spp, uint32_t ray_tracing_depth)
    : spp{ spp }
    , ray_tracing_depth{ ray_tracing_depth } {}

void Integrator::render(std::shared_ptr<Scene> const& scene, std::shared_ptr<Camera> const& camera) {
    std::atomic<uint32_t> scanline_finished{ 0 };

    auto single_thread_render_func = [&]() {
        auto image_width{ camera->get_film().width };
        auto image_height{ camera->get_film().height };
        // Per thread rng for non-competitive access.
        RandomNumberGenerator rng{};

        for (uint32_t j{ scanline_finished.fetch_add(1, std::memory_order_relaxed) }; j < image_height; j = scanline_finished.fetch_add(1, std::memory_order_relaxed)) {
            std::printf("\rScanlines remaining: %u ", image_height - j - 1);
            std::fflush(stdout);

            for (uint32_t i{ 0 }; i < image_width; ++i) {
                Color3f pixel_color{ Color3f::Zero() };
                for (uint32_t s{ 0 }; s < this->spp; ++s) {
                    Ray ray{ camera->generate_ray(i, j, rng) };
                    pixel_color += this->radiance(scene, ray, rng, 0);
                }
                camera->set_pixel(i, j, pixel_color / this->spp);
            }
        }
    };

    // Create and launch the threads.
    std::vector<std::thread> threads;
    auto num_threads{ std::thread::hardware_concurrency() };
    std::printf("Number of threads: %u.\n", num_threads);
    for (uint32_t _{ 0 }; _ < num_threads; ++_) {
        threads.emplace_back(single_thread_render_func);
    }
    for (auto&& t : threads) {
        t.join();
    }

    std::printf("\nRendering Done!\n");
}

Color3f Integrator::radiance(std::shared_ptr<Scene> const& scene, Ray const& ray, RandomNumberGenerator& rng, uint32_t current_depth) {
    if (current_depth > this->ray_tracing_depth) {
        return Color3f::Zero();
    }

    Interaction interaction;
    // `t_min` < 5e-5 is not a good choice for avoiding self shadow acne.
    if (scene->hit(ray, 1e-3_f, INF<Float>, &interaction)) {
        Ray scattered;
        Color3f attenuation;
        if (interaction.mat_ptr->scatter(ray, interaction, rng, &attenuation, &scattered)) {
            return attenuation.cwiseProduct(this->radiance(scene, scattered, rng, current_depth + 1));
        }
        else {
            return Color3f::Zero();
        }
    }

    auto unit_dir{ ray.direction.normalized() };
    auto t{ (unit_dir.y() + 1.0_f) * 0.5_f };
    return lerp(Color3f{ 1.0, 1.0, 1.0 }, Color3f{ 0.5, 0.7, 1.0 }, t);
}

CS100_RAY_TRACING_NAMESPACE_END
