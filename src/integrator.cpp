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

#include <cassert>
#include <cstdio>

#include "math-utils.h"
#include "geometry/sphere.h"

void render(Camera const* camera) {
    uint32_t image_width{ camera->get_film().get_width() };
    uint32_t image_height{ camera->get_film().get_height() };
    for (uint32_t j{ 0 }; j < image_height; ++j) {
        std::printf("\rScanlines remaining: %u ", image_height - j - 1);
        std::fflush(stdin);

        for (uint32_t i{ 0 }; i < image_width; ++i) {
            Ray ray{ camera->generate_ray(i, j) };
            Color3f color{ radiance(ray) };
            camera->set_pixel(i, j, color);
        }
    }
    std::printf("\nRendering done.\n");
}

Color3f radiance(Ray const& ray) {
    Sphere s { Point3f{ 0.0, 0.0, -1.0 }, 0.5_f };
    Interaction interaction;
    if (s.hit(ray, 0.0, INF, &interaction)) {
        // Visualize the normal of the sphere.
        return vector3_scalar_mul(vector3_add(interaction.normal, Vector3f{ 1.0, 1.0, 1.0 }), 0.5_f);
    }

    // The background sky.
    Vector3f unit_dir{ vector3_unit(ray.direction) };
    Float t{ 0.5_f * (unit_dir.y + 1.0_f) };
    return vector3_lerp(Color3f{ 1.0, 1.0, 1.0 }, Color3f{ 0.5, 0.7, 1.0 }, t);
}
