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
    std::string type{ config.at("type") };

    if (type == "Sphere") {
        return std::make_shared<Sphere>(
            from_json(config.at("center")),
            config.at("radius"),
            Material::create(config.at("material")));
    }
    else if (type == "RandomScene") {
        return Geometry::create_random_scene();
    }
    else {
        throw std::runtime_error{ "Unknown geometry type: " + type };
    }
}

std::shared_ptr<Geometry> Geometry::create_random_scene() {
    std::vector<std::shared_ptr<Geometry>> objects;
    RandomNumberGenerator rng{};

    for (int32_t a = -11; a < 11; ++a) {
        for (int32_t b = -11; b < 11; ++b) {
            Float choose_mat{ rng() };
            Point3f center{ a + 0.9_f * rng(), 0.2_f, b + 0.9_f * rng() };

            if ((center - Point3f{ 4, 0.2, 0 }).norm() > 0.9) {
                std::shared_ptr<Material> sphere_material;

                if (choose_mat < 0.8) {
                    // Diffuse.
                    Color3f albedo{ random_vector3f(rng).cwiseProduct(random_vector3f(rng)) };
                    sphere_material = std::make_shared<Lambertian>(albedo);
                    objects.push_back(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
                else if (choose_mat < 0.95) {
                    // Metal.
                    auto albedo{ random_vector3f(rng, 0.5_f, 1.0_f) };
                    auto fuzz{ rng() * 0.5_f };
                    sphere_material = std::make_shared<Metal>(albedo, fuzz);
                    objects.push_back(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
                else {
                    // Glass.
                    sphere_material = std::make_shared<Dielectric>(1.5);
                    objects.push_back(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }
    return std::make_shared<Scene>(objects);
}

CS100_RAY_TRACING_NAMESPACE_END
