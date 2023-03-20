/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of lambertian material.
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

#include "material/lambertian.h"

#include <limits>

CS100_RAY_TRACING_NAMESPACE_BEGIN

Lambertian::Lambertian(Color3f const& albedo)
    : albedo{ albedo } {}

bool Lambertian::scatter([[maybe_unused]] Ray const& ray, Interaction const& interaction, RandomNumberGenerator& rng, Color3f* attenuation, Ray* scattered) const {
    Vector3f target_direction{ interaction.normal + random_vector3f_in_unit_sphere(rng).normalized() };

    // Catch degenerate scatter direction.
    if (target_direction.isZero(std::numeric_limits<Float>::epsilon())) {
        target_direction = interaction.normal;
    }

    *attenuation = this->albedo;
    *scattered = { interaction.hit_point, target_direction };
    return true;
}

CS100_RAY_TRACING_NAMESPACE_END
