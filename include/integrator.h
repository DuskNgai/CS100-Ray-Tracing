/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of the integrator, which calculate the radiance of a ray.
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

#ifndef _CS100_RAY_TRACING_INTEGRATOR_H_
#define _CS100_RAY_TRACING_INTEGRATOR_H_

#include "camera.h"
#include "geometry/scene.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

/// @brief The integrator is responsible for computing the radiance along a ray
/// and rendering the scene to camera film.
class Integrator {
private:
    uint32_t spp;
    uint32_t ray_tracing_depth;

public:
    /// @brief Construct a new Integrator object.
    /// @param spp The number of samples per pixel.
    /// @param ray_tracing_depth The maximum recursion depth of the ray.
    Integrator(uint32_t spp, uint32_t ray_tracing_depth);
    ~Integrator() = default;

    /// @brief Render the scene with the given camera.
    /// @param scene The scene to be rendered.
    /// @param camera The camera used to render the scene.
    void render(std::shared_ptr<Scene> const& scene, std::shared_ptr<Camera> const& camera);

    /// @brief The integrator is responsible for computing the radiance along a ray.
    /// @param scene The scene to be rendered.
    /// @param ray The ray to be traced.
    /// @param rng The random number generator used for sampling.
    /// @param current_depth The current recursion depth of the ray.
    /// @return The radiance along the ray.
    Color3f radiance(std::shared_ptr<Scene> const& scene, Ray const& ray, RandomNumberGenerator& rng, uint32_t current_depth);
};

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_INTEGRATOR_H_
