/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of metal material.
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


#include "material/metal.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

Metal::Metal(Color3f const& albedo, Float fuzz)
    : albedo{ albedo }
    , fuzz{ fuzz < 1.0_f ? fuzz : 1.0_f } {}

bool Metal::scatter(Ray const& ray, Interaction const& interaction, RandomNumberGenerator& rng, Color3f* attenuation, Ray* scattered) const {
    Vector3f reflected{ reflect(ray.direction.normalized(), interaction.normal) };
    *scattered = { interaction.hit_point, reflected + fuzz * random_vector3f_in_unit_sphere(rng) };
    *attenuation = albedo;
    return scattered->direction.dot(interaction.normal) > 0;
}

CS100_RAY_TRACING_NAMESPACE_END
