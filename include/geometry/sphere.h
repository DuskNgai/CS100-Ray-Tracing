/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of a sphere.
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

#ifndef _CS100_RAY_TRACING_SPHERE_H_
#define _CS100_RAY_TRACING_SPHERE_H_

#include "geometry/geometry.h"

/// @brief The definition of a sphere.
typedef struct Sphere {
    Geometry super;
    Point3 center;
    Float radius;
} Sphere;

/// @brief Create a Sphere object.
/// @param center The center of the sphere.
/// @param radius The radius of the sphere.
/// @return A Sphere object.
Sphere sphere_create(Point3 center, Float radius);

/// @brief Test if a ray intersects with a sphere.
/// @param object The sphere object.
/// @param ray The ray.
/// @param t_min The minimum t value.
/// @param t_max The maximum t value.
/// @param interaction The interaction record.
/// @return True if the ray intersects with the sphere.
bool sphere_hit(void* object, Ray const* ray, Float t_min, Float t_max, Interaction* interaction);

#endif // !_CS100_RAY_TRACING_SPHERE_H_
