/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of a 3D vector and some operations on it.
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

#include <math.h>

#include "vec3.h"

// Generic selection, a c11 standard feature.
// https://en.cppreference.com/w/c/language/generic
#define sqrt(x)            \
    _Generic((x),          \
        float: sqrtf,      \
        double: sqrt,      \
        long double: sqrtl \
    )(x)

Vec3 vec3_add(Vec3 const* u, Vec3 const* v) {
    Vec3 res = {
        .x = u->x + v->x,
        .y = u->y + v->y,
        .z = u->z + v->z
    };
    return res;
}

Vec3 vec3_sub(Vec3 const* u, Vec3 const* v) {
    Vec3 res = {
        .x = u->x - v->x,
        .y = u->y - v->y,
        .z = u->z - v->z
    };
    return res;
}

Vec3 vec3_neg(Vec3 const* u) {
    Vec3 res = {
        .x = -u->x,
        .y = -u->y,
        .z = -u->z
    };
    return res;
}

Vec3 vec3_scale_mul(Vec3 const* u, Float a) {
    Vec3 res = {
        .x = u->x * a,
        .y = u->y * a,
        .z = u->z * a
    };
    return res;
}

Vec3 vec3_scale_div(Vec3 const* u, Float a) {
    return vec3_scale_mul(u, 1.0 / a);
}

Float vec3_dot(Vec3 const* u, Vec3 const* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

Vec3 vec3_cross(Vec3 const* u, Vec3 const* v) {
    Vec3 res = {
        .x = u->y * v->z - u->z * v->y,
        .y = u->z * v->x - u->x * v->z,
        .z = u->x * v->y - u->y * v->x
    };
    return res;
}

Float vec3_norm(Vec3 const* u) {
    return sqrt(vec3_dot(u, u));
}

Float vec3_square_norm(Vec3 const* u) {
    return vec3_dot(u, u);
}

Vec3 vec3_unit(Vec3 const* u) {
    return vec3_scale_div(u, vec3_norm(u));
}
