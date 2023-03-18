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

CS100_RAY_TRACING_NAMESPACE_BEGIN

Sphere::Sphere(Point3f const& center, Float radius, std::shared_ptr<Material> const& mat_ptr)
    : center{ center }
    , radius{ radius }
    , mat_ptr{ mat_ptr } {}

bool Sphere::hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const {
    Vector3f oc{ ray.origin - this->center };

    // Convert to a quadratic equation.
    Float a{ ray.direction.squaredNorm() };
    Float b_half{ oc.dot(ray.direction) };
    Float c{ oc.squaredNorm() - this->radius * this->radius };
    Float discriminant{ b_half * b_half - a * c };

    if (discriminant < 0.0_f) {
        return false;
    }

    // Find and check the root.
    Float sqrt_discriminant{ std::sqrt(discriminant) };
    Float t{ (-b_half - sqrt_discriminant) / a };
    if (t < t_min || t > t_max) {
        t = (-b_half + sqrt_discriminant) / a;
        if (t < t_min || t > t_max) {
            return false;
        }
    }

    // Record this interaction.
    interaction->t = t;
    interaction->hit_point = ray.at(t);
    interaction->set_face_normal(ray, (interaction->hit_point - this->center) / this->radius);
    interaction->mat_ptr = this->mat_ptr;
    return true;
}

CS100_RAY_TRACING_NAMESPACE_END
