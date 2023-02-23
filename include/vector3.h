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

#include <array>
#include <iostream>

#include "math-utils.h"

/// @brief A 3D vector.
template <typename T>
struct Vector3 {
    union {
        struct {
            T x, y, z;
        };
        std::array<Float, 3> data {0, 0, 0};
    };

    // Constructors.
    Vector3() = default;
    Vector3(T x, T y, T z)
        : data{ x, y, z } {}
    Vector3(Vector3 const& v)
        : data{ v.data } {}
    Vector3(Vector3 &&v) noexcept
        : data{ std::move(v.data) } {}
    Vector3& operator=(Vector3 const& v) {
        if (this != &v) {
            x = v.x;
            y = v.y;
            z = v.z;
        }
        return *this;
    }
    Vector3 &operator=(Vector3 &&v) noexcept {
        x = std::move(v.x);
        y = std::move(v.y);
        z = std::move(v.z);
        return *this;
    }
    ~Vector3() = default;

    // Access function.
    T &operator[](std::size_t i) { return this->data[i]; }
    T const &operator[](std::size_t i) const { return this->data[i]; }

    // Operations.
    Vector3& operator+=(Vector3 const& v) {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
        return *this;
    }
    Vector3& operator-=(Vector3 const& v) {
        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;
        return *this;
    }
    Vector3& operator*=(T a) {
        this->x *= a;
        this->y *= a;
        this->z *= a;
        return *this;
    }
    Vector3& operator/=(T a) {
        return *this *= (static_cast<T>(1) / a);
    }

    /// @brief |v|
    T constexpr norm() const { return std::sqrt(this->square_norm()); }
    /// @brief |v|^2
    T constexpr square_norm() const { return dot(*this, *this); }
    /// @brief v / |v|
    Vector3 constexpr unit() const { return *this / this->norm(); }
};

// Operations.

template <typename T>
Vector3<T> constexpr operator+(Vector3<T> const& u, Vector3<T> const& v) {
    return Vector3<T>{u} += v;
}

template <typename T>
Vector3<T> constexpr operator-(Vector3<T> const& u, Vector3<T> const& v) {
    return Vector3<T>{u} -= v;
}

template <typename T, typename U>
Vector3<std::enable_if_t<std::is_convertible_v<T, U>, T>> constexpr operator*(Vector3<T> const& u, U a) {
    return Vector3<T>{u} *= a;
}

template <typename T, typename U>
Vector3<std::enable_if_t<std::is_convertible_v<T, U>, T>> constexpr operator*(U a, Vector3<T> const& u) {
    return u * a;
}

template <typename T, typename U>
Vector3<std::enable_if_t<std::is_convertible_v<T, U>, T>> constexpr operator/(Vector3<T> const& u, U a) {
    return u * (static_cast<T>(1.0) / a);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Vector3<T> const& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

/// @brief <u, v>.
template <typename T>
T constexpr dot(Vector3<T> const& u, Vector3<T> const& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

/// @brief u x v.
template <typename T>
Vector3<T> constexpr cross(Vector3<T> const& u, Vector3<T> const& v) {
    return {
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    };
}

/// @brief u * (1 - t) + v * t.
template <typename T, typename FloatingPoint>
Vector3<T> constexpr lerp(Vector3<T> const& u, Vector3<T> const& v, FloatingPoint t) {
    return u + (v - u) * t;
}

using Vector3f = Vector3<Float>;
using Color3f = Vector3f;
using Point3f = Vector3f;

#endif // !_CS100_RAY_TRACING_VECTOR3_H_
