/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of the integrator.
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

#include "geometry/sphere.h"

Color3 radiance(const Ray* ray) {
    Sphere s = sphere_create((Point3){ 0.0, 0.0, -1.0 }, 0.5);
    if (s.hit(&s, ray, 0.0, INF)) {
        return (Color3){ 1.0, 0.0, 0.0 };
    }
    Vec3 unit_dir = vec3_unit(ray->direction);
    Float t = (Float)0.5 * (unit_dir.y + (Float)1.0);
    return vec3_lerp((Color3){ 1, 1, 1 }, (Color3){ 0.5, 0.7, 1.0 }, t);
}
