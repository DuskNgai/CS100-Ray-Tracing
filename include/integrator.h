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

class Integrator {
private:
    uint32_t spp;
    uint32_t depth;
    RandomNumberGenerator rng{};

public:
    Integrator(uint32_t spp, uint32_t depth);
    ~Integrator() = default;

    /// @brief Render the scene with the given camera.
    /// @param camera The camera used to render the scene.
    /// @param scene The scene to be rendered.
    void render(Camera const& camera, Scene const& scene);

    /// @brief The integrator is responsible for computing the radiance along a ray.
    /// @param ray The ray to be traced.
    /// @param scene The scene to be rendered.
    /// @param current_depth The current recursion depth of the ray.
    /// @return The radiance along the ray.
    Color3f radiance(Ray const& ray, Scene const& scene, uint32_t current_depth);
};

#endif // !_CS100_RAY_TRACING_INTEGRATOR_H_
