/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of a 3D vector and some operations on it.
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

#ifndef _CS100_RAY_TRACING_VEC3_H_
#define _CS100_RAY_TRACING_VEC3_H_

#include "math-utils.h"

/// @brief u 3D vector.
typedef struct Vec3 {
    Float x, y, z;
} Vec3;

// Operations on Vec3.

/// @brief u + v.
Vec3 vec3_add(Vec3 u, Vec3 v);

/// @brief u - v.
Vec3 vec3_sub(Vec3 u, Vec3 v);

/// @brief -u.
Vec3 vec3_neg(Vec3 u);

/// @brief u * a.
Vec3 vec3_scale_mul(Vec3 u, Float a);

/// @brief u / a.
Vec3 vec3_scale_div(Vec3 u, Float a);

// Properties of Vec3.

/// @brief <u, v>.
Float vec3_dot(Vec3 u, Vec3 v);

/// @brief u x v.
Vec3 vec3_cross(Vec3 u, Vec3 v);

/// @brief |u|.
Float vec3_norm(Vec3 u);

/// @brief |u|^2.
Float vec3_square_norm(Vec3 u);

/// @brief u / |u|.
Vec3 vec3_unit(Vec3 u);

/// @brief u * (1 - t) + v * t.
Vec3 vec3_lerp(Vec3 u, Vec3 v, Float t);

typedef Vec3 Color3;
typedef Vec3 Point3;

#endif // !_CS100_RAY_TRACING_VEC3_H_
