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

#include "material/material.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

std::shared_ptr<Material> Material::create(nlohmann::json const& config) {
    std::string type{ config.at("type") };

    if (type == "Lambertian") {
        return std::make_shared<Lambertian>(from_json(config.at("albedo")));
    }
    else if (type == "Metal") {
        return std::make_shared<Metal>(
            from_json(config.at("albedo")),
            config.at("fuzz"));
    }
    else {
        throw std::runtime_error{ "Unknown material type: " + type };
    }
}

CS100_RAY_TRACING_NAMESPACE_END
