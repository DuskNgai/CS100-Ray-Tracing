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

#include <cmath>
#include <limits>

using Float = float;

// See https://en.cppreference.com/w/cpp/language/user_literal.
Float inline constexpr operator""_f(long double x) { return static_cast<Float>(x); }

// clang-format off
template <typename FloatingPoint> constexpr FloatingPoint PI  = static_cast<FloatingPoint>(3.141592653589793238462643383279);
template <typename FloatingPoint> constexpr FloatingPoint INF = std::numeric_limits<FloatingPoint>::max();
// clang-format on

/// @brief Convert degrees to radians.
/// @param deg The degrees.
/// @return The radians.
Float inline constexpr deg_to_rad(Float deg) {
    return deg * PI<Float> / 180.0_f;
}

#endif // !_CS100_RAY_TRACING_MATH_UTILS_H_
