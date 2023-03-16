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

#ifndef _CS100_RAY_TRACING_VECTOR3_H_
#define _CS100_RAY_TRACING_VECTOR3_H_

#include <Eigen/Dense>
#include <iostream>
#include <nlohmann/json.hpp>

#include "math-utils.h"
#include "utils/random-number-generator.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

template <typename T>
using Vector3 = Eigen::Vector3<T>;
using Vector3f = Eigen::Vector3<Float>;
using Color3f = Vector3f;
using Point3f = Vector3f;

/// @brief u * (1 - t) + v * t.
template <typename T, typename FloatingPoint>
Vector3<T> constexpr lerp(Vector3<T> const& u, Vector3<T> const& v, FloatingPoint t) {
    return u + (v - u) * t;
}

/// @brief Reflect the incoming direction `v` respect to the normal `n`.
template <typename T>
Vector3<T> constexpr reflect(Vector3<T> const& v, Vector3<T> const& n) {
    return v - 2.0_f * v.dot(n) * n;
}

/// @brief A random vector in [min, max]^3.
Vector3f inline random_vector3f(RandomNumberGenerator& rng, Float min = 0.0_f, Float max = 1.0_f) {
    return Vector3f{ rng(), rng(), rng() } * (max - min) + Vector3f{ min, min, min };
}

/// @brief A random vector who is in a unit sphere.
Vector3f inline random_vector3f_in_unit_sphere(RandomNumberGenerator& rng) {
    while (true) {
        auto p{ random_vector3f(rng, -1.0_f, 1.0_f) };
        if (p.squaredNorm() <= 1.0_f) {
            return p;
        }
    }
}

/// @brief Convert array in configuration file to `Vector3f`.
Vector3f inline from_json(nlohmann::json const& config) {
    Vector3f v;
    for (std::size_t i = 0; i < 3; ++i) {
        v[i] = config[i];
    }
    return v;
}

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_VECTOR3_H_
