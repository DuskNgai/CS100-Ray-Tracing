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

#include "vector3.h"

Vector3f vector3_add(Vector3f u, Vector3f v) {
    Vector3f res = {
        .x = u.x + v.x,
        .y = u.y + v.y,
        .z = u.z + v.z
    };
    return res;
}

Vector3f vector3_sub(Vector3f u, Vector3f v) {
    Vector3f res = {
        .x = u.x - v.x,
        .y = u.y - v.y,
        .z = u.z - v.z
    };
    return res;
}

Vector3f vector3_neg(Vector3f u) {
    Vector3f res = {
        .x = -u.x,
        .y = -u.y,
        .z = -u.z
    };
    return res;
}

Vector3f vector3_scalar_mul(Vector3f u, Float a) {
    Vector3f res = {
        .x = u.x * a,
        .y = u.y * a,
        .z = u.z * a
    };
    return res;
}

Vector3f vector3_scalar_div(Vector3f u, Float a) {
    return vector3_scalar_mul(u, (Float)1.0 / a);
}

Float vector3_dot(Vector3f u, Vector3f v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3f vector3_cross(Vector3f u, Vector3f v) {
    Vector3f res = {
        .x = u.y * v.z - u.z * v.y,
        .y = u.z * v.x - u.x * v.z,
        .z = u.x * v.y - u.y * v.x
    };
    return res;
}

Float vector3_norm(Vector3f u) {
    return sqrt(vector3_square_norm(u));
}

Float vector3_square_norm(Vector3f u) {
    return vector3_dot(u, u);
}

Vector3f vector3_unit(Vector3f u) {
    return vector3_scalar_div(u, vector3_norm(u));
}

Vector3f vector3_lerp(Vector3f u, Vector3f v, Float t) {
    return vector3_add(u, vector3_scalar_mul(vector3_sub(v, u), t));
}