/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of scene class that contains all geometry objects.
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

#include "geometry/scene.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

Scene::Scene(decltype(Scene::objects) const& objects)
    : objects{ objects } {}

Scene::Scene(std::initializer_list<std::shared_ptr<Geometry>> objects)
    : objects{ objects } {}

void Scene::add_object(std::shared_ptr<Geometry> const& object) {
    objects.push_back(object);
}

void Scene::clear_objects() {
    objects.clear();
}

decltype(Scene::objects) const& Scene::get_objects() const {
    return objects;
}

bool Scene::hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const {
    bool hit_anything{ false };
    Float closest_so_far{ t_max };
    Interaction local_interaction;
    for (auto const& object : this->objects) {
        // Update to the closest interaction.
        if (object->hit(ray, t_min, closest_so_far, &local_interaction)) {
            hit_anything = true;
            closest_so_far = local_interaction.t;
            *interaction = local_interaction;
        }
    }
    return hit_anything;
}

std::shared_ptr<Scene> Scene::create(nlohmann::json const& config) {
    decltype(Scene::objects) objects;

    for (auto const& c : config) {
        objects.push_back(Geometry::create(c));
    }

    return std::make_shared<Scene>(objects);
}

CS100_RAY_TRACING_NAMESPACE_END
