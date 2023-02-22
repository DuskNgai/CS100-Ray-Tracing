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

void Integrator::render(Camera const& camera, Scene const& scene) {
    for (uint32_t j = 0; j < camera.get_film().height; ++j) {
        fprintf(stderr, "\rScanlines remaining: %u ", camera.get_film().height - j - 1);
        fflush(stderr);

        for (uint32_t i = 0; i < camera.get_film().width; ++i) {
            Ray ray = camera.generate_ray(i, j);
            Color3f color = this->radiance(ray, scene);
            camera.set_pixel(i, j, color);
        }
    }
}

Color3f Integrator::radiance(Ray const& ray, Scene const& scene) {
    Interaction interaction;
    if (scene.hit(ray, 0.0, INF<Float>, &interaction)) {
        return (interaction.normal + Vector3f{ 1.0, 1.0, 1.0 }) * static_cast<Float>(0.5);
    }

    Vector3f unit_dir = ray.direction.unit();
    Float t = (unit_dir.y + static_cast<Float>(1.0)) * static_cast<Float>(0.5);
    return lerp(Color3f{ 1.0, 1.0, 1.0 }, Color3f{ 0.5, 0.7, 1.0 }, t);
}
