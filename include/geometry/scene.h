/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of scene class that contains all geometry objects.
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

#ifndef _CS100_RAY_TRACING_SCENE_H_
#define _CS100_RAY_TRACING_SCENE_H_

#include <memory>
#include <vector>

#include "geometry/geometry.h"

class Scene : public Geometry {
private:
    std::vector<std::shared_ptr<Geometry>> objects;

public:
    Scene() = default;
    Scene(std::initializer_list<std::shared_ptr<Geometry>> objects);
    Scene(std::vector<std::shared_ptr<Geometry>> const& objects);
    Scene(Scene const& other) = delete;
    Scene& operator=(Scene const& other) = delete;

    void add_object(std::shared_ptr<Geometry> const& object);
    void clear_objects();
    std::vector<std::shared_ptr<Geometry>> const& get_objects() const;

    virtual bool hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const override;
};

#endif // !_CS100_RAY_TRACING_SCENE_H_
