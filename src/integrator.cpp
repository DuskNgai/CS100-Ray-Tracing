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

#include <cstdio>

Integrator::Integrator(uint32_t spp, uint32_t ray_tracing_depth)
    : spp(spp)
    , ray_tracing_depth(ray_tracing_depth) {}

void Integrator::render(std::shared_ptr<Camera> const& camera, std::shared_ptr<Scene> const& scene) {
    for (uint32_t j = 0; j < camera->get_film().height; ++j) {
        std::printf("\rScanlines remaining: %u ", camera->get_film().height - j - 1);
        std::fflush(stdout);

        for (uint32_t i = 0; i < camera->get_film().width; ++i) {
            Color3f pixel_color;
            for (uint32_t s = 0; s < this->spp; ++s) {
                Ray ray = camera->generate_ray(i, j, this->rng);
                pixel_color += this->radiance(ray, scene, 0);
            }
            camera->set_pixel(i, j, pixel_color / this->spp);
        }
    }
}

Color3f Integrator::radiance(Ray const& ray, std::shared_ptr<Scene> const& scene, uint32_t current_depth) {
    if (current_depth > this->ray_tracing_depth) {
        return { 0.0, 0.0, 0.0 };
    }

    Interaction interaction;
    // `t_min` < 5e-5 is not a good choice for avoiding self shadow acne.
    if (scene->hit(ray, 1e-3_f, INF<Float>, &interaction)) {
        auto target = interaction.hit_point + interaction.normal + random_vector3f_in_unit_sphere(this->rng).unit();
        return 0.5_f * this->radiance(Ray{ interaction.hit_point, target - interaction.hit_point }, scene, current_depth + 1);
    }

    Vector3f unit_dir = ray.direction.unit();
    Float t = (unit_dir.y + 1.0_f) * 0.5_f;
    return lerp(Color3f{ 1.0, 1.0, 1.0 }, Color3f{ 0.5, 0.7, 1.0 }, t);
}
