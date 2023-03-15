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

#include "math-utils.h"
#include "geometry/sphere.h"

void render(Camera const* camera) {
    uint32_t image_width = camera->film->width;
    uint32_t image_height = camera->film->height;
    for (uint32_t j = 0; j < image_height; ++j) {
        printf("\rScanlines remaining: %u ", image_height - j - 1);
        fflush(stdin);

        for (uint32_t i = 0; i < image_width; ++i) {
            Ray ray = camera_generate_ray(camera, i, j);
            Color3f color = radiance(&ray);
            camera_set_pixel(camera, i, j, color);
        }
    }
    printf("\nRendering done.\n");
}

Color3f radiance(Ray const* ray) {
    assert(ray != NULL);

    Sphere s = { (Point3f){ 0.0, 0.0, -1.0 }, (Float)0.5 };
    Interaction interaction;
    if (sphere_hit(&s, ray, 0.0, INF, &interaction)) {
        // Visualize the normal of the sphere.
        return vector3_scalar_mul(vector3_add(interaction.normal, (Vector3f){ 1.0, 1.0, 1.0 }), (Float)0.5);
    }

    // The background sky.
    Vector3f unit_dir = vector3_unit(ray->direction);
    Float t = (Float)0.5 * (unit_dir.y + (Float)1.0);
    return vector3_lerp((Color3f){ 1.0, 1.0, 1.0 }, (Color3f){ 0.5, 0.7, 1.0 }, t);
}
