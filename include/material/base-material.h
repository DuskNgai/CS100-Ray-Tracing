/*
 * CS100-Ray-Tracing for course recitation.
 * The abstract class for all material.
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

#ifndef _CS100_RAY_TRACING_MATERIAL_BASE_MATERIAL_H_
#define _CS100_RAY_TRACING_MATERIAL_BASE_MATERIAL_H_

#include "geometry/interaction.h"
#include "ray.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

/// @brief The abstract material class that defines the material of a geometry object.
struct Material {
public:
    /// @brief Produce a scattered ray once the ray hits the geometry object.
    /// @param ray The in scattering ray.
    /// @param interaction The interaction information.
    /// @param rng The random number generator.
    /// @param attenuation The attenuation of the scattered ray.
    /// @param scattered The out scattered ray.
    /// @return True if there is a scattered ray.
    virtual bool scatter(Ray const& ray, Interaction const& interaction, RandomNumberGenerator& rng, Color3f* attenuation, Ray* scattered) const = 0;

    /// @brief Create a material object based on given configuration.
    static std::shared_ptr<Material> create(nlohmann::json const& config);
};

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_MATERIAL_BASE_MATERIAL_H_
