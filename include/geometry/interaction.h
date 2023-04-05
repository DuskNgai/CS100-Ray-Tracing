/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of ray-object interaction, which records the intersection imformation.
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

#ifndef _CS100_RAY_TRACING_INTERACTION_H_
#define _CS100_RAY_TRACING_INTERACTION_H_

#include "math-utils.h"
#include "vector3.h"

/// @brief The record for interaction between a ray and an object.
struct Interaction {
    Float t;
    Point3f hit_point;
    Vector3f normal;
};

#endif // !_CS100_RAY_TRACING_INTERACTION_H_
