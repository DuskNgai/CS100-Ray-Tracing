/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of a sphere.
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

#include "geometry/sphere.h"

Sphere::Sphere(Point3f const& center, Float radius)
    : center(center), radius(radius) {}

bool Sphere::hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const {
    Vector3f oc = ray.origin - this->center;

    // Convert to a quadratic equation.
    Float a = ray.direction.square_norm();
    Float b_half = dot(oc, ray.direction);
    Float c = oc.square_norm() - this->radius * this->radius;
    Float discriminant = b_half * b_half - a * c;

    if (discriminant < 0) {
        return false;
    }

    // Find and check the root.
    Float sqrt_discriminant = std::sqrt(discriminant);
    Float t = (-b_half - sqrt_discriminant) / a;
    if (t < t_min || t > t_max) {
        t = (-b_half + sqrt_discriminant) / a;
        if (t < t_min || t > t_max) {
            return false;
        }
    }

    // Record this interaction.
    interaction->t = t;
    interaction->hit_point = ray.at(t);
    interaction->normal = (interaction->hit_point - this->center) / this->radius;
    return true;
}
