/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of a ray.
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

#include "ray.h"

Point3 ray_at(Ray const* r, Float t) {
    Point3 res = {
        .x = r->origin.x + t * r->direction.x,
        .y = r->origin.y + t * r->direction.y,
        .z = r->origin.z + t * r->direction.z
    };
    return res;
}