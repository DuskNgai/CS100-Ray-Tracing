/*
 * CS100-Ray-Tracing for course recitation.
 * The abstract class for all geometry objects.
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

#include "geometry/geometry.h"
#include "material/material.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

std::shared_ptr<Geometry> Geometry::create(nlohmann::json const& config) {
    nlohmann::json cfg = config.at("geometry");
    std::string type{ cfg.at("type") };

    if (type == "Sphere") {
        return std::make_shared<Sphere>(
            from_json(cfg.at("center")),
            cfg.at("radius"),
            Material::create(cfg.at("material")));
    }
    else {
        throw std::runtime_error{ "Unknown geometry type: " + type };
    }
}

CS100_RAY_TRACING_NAMESPACE_END
