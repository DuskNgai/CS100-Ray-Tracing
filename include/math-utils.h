/*
 * CS100-Ray-Tracing for course recitation.
 * A header file for math utilities.
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

#ifndef _CS100_RAY_TRACING_MATH_UTILS_H_
#define _CS100_RAY_TRACING_MATH_UTILS_H_

#include <math.h>

typedef float Float;

#define INF HUGE_VAL
#define PI ((Float)3.14159265358979323846)

// Generic selection, a c11 standard feature.
// https://en.cppreference.com/w/c/language/generic
// clang-format off
#define sqrt(x)            \
    _Generic((x),          \
        float: sqrtf,      \
        double: sqrt,      \
        long double: sqrtl \
    )(x)

#define pow(x, y)         \
    _Generic((x),         \
        float: powf,      \
        double: pow,      \
        long double: powl \
    )(x, y)
// clang-format on

/// @brief Convert degrees to radians.
/// @param deg The degrees.
/// @return The radians.
Float deg_to_rad(Float deg);

#endif // !_CS100_RAY_TRACING_MATH_UTILS_H_
