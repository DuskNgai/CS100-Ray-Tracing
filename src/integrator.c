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

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "geometry/sphere.h"

void render(Camera const* camera, Scene const* scene) {
    for (uint32_t j = 0; j < camera->film->height; ++j) {
        fprintf(stderr, "\rScanlines remaining: %u ", camera->film->height - j - 1);
        fflush(stderr);

        for (uint32_t i = 0; i < camera->film->width; ++i) {
            Ray ray = camera_generate_ray(camera, i, j);
            Color3f color = radiance(&ray, scene);
            camera_set_pixel(camera, i, j, color);
        }
    }
}

Color3f radiance(Ray const* ray, Scene const* scene) {
    assert(ray != NULL);
    assert(scene != NULL);

    Interaction interaction;
    if (scene_hit(scene, ray, 0.0, INF, &interaction)) {
        return vector3_scalar_mul(vector3_add(interaction.normal, (Vector3f){ 1.0, 1.0, 1.0 }), (Float)0.5);
    }

    Vector3f unit_dir = vector3_unit(ray->direction);
    Float t = (Float)0.5 * (unit_dir.y + (Float)1.0);
    return vector3_lerp((Color3f){ 1.0, 1.0, 1.0 }, (Color3f){ 0.5, 0.7, 1.0 }, t);
}
