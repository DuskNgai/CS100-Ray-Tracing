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

#include "geometry/sphere.h"

Color3 radiance(const Ray* ray) {
    assert(ray != NULL);

    Sphere s = { (Point3){ 0.0, 0.0, -1.0 }, 0.5 };
    Interaction interaction;
    if (sphere_hit(&s, ray, 0.0, INF, &interaction)) {
        return vec3_scalar_mul(vec3_add(interaction.normal, (Vec3){ 1.0, 1.0, 1.0 }), (Float)0.5);
    }

    Vec3 unit_dir = vec3_unit(ray->direction);
    Float t = (Float)0.5 * (unit_dir.y + (Float)1.0);
    return vec3_lerp((Color3){ 1, 1, 1 }, (Color3){ 0.5, 0.7, 1.0 }, t);
}
