/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of a sphere.
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

#include "geometry/sphere.h"

Sphere sphere_create(Vec3 center, Float radius) {
    Sphere res = {
        .center = center,
        .radius = radius,
        .hit = sphere_hit
    };
    return res;
}

bool sphere_hit(void* object, Ray const* ray, Float t_min, Float t_max) {
    Sphere* sphere = (Sphere*)object;
    Vec3 oc = vec3_sub(ray->origin, sphere->center);

    Float a = vec3_square_norm(ray->direction);
    Float b_half = vec3_dot(oc, ray->direction);
    Float c = vec3_square_norm(oc) - sphere->radius * sphere->radius;
    Float discriminant = b_half * b_half - a * c;

    if (discriminant < 0) {
        return false;
    }
    else {
        Float t = (-b_half - sqrt(discriminant)) / a;
        if (t < t_min || t > t_max) {
            t = (-b_half + sqrt(discriminant)) / a;
            if (t < t_min || t > t_max) {
                return false;
            }
        }
        return true;
    }
}
