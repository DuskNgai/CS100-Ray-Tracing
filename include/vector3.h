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

/// @brief A 3D vector.
typedef struct Vector3f {
    Float x, y, z;
} Vector3f;

// Operations on Vector3f.

/// @brief u + v.
Vector3f vector3_add(Vector3f u, Vector3f v);

/// @brief u - v.
Vector3f vector3_sub(Vector3f u, Vector3f v);

/// @brief -u.
Vector3f vector3_neg(Vector3f u);

/// @brief u * a.
Vector3f vector3_scalar_mul(Vector3f u, Float a);

/// @brief u / a.
Vector3f vector3_scalar_div(Vector3f u, Float a);

// Properties of Vector3f.

/// @brief <u, v>.
Float vector3_dot(Vector3f u, Vector3f v);

/// @brief u x v.
Vector3f vector3_cross(Vector3f u, Vector3f v);

/// @brief |u|.
Float vector3_norm(Vector3f u);

/// @brief |u|^2.
Float vector3_square_norm(Vector3f u);

/// @brief u / |u|.
Vector3f vector3_unit(Vector3f u);

/// @brief u * (1 - t) + v * t.
Vector3f vector3_lerp(Vector3f u, Vector3f v, Float t);

typedef Vector3f Color3f;
typedef Vector3f Point3f;

#endif // !_CS100_RAY_TRACING_VEC3_H_
