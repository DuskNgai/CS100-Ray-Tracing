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

#include <stdint.h>

#include "geometry/sphere.h"

/// @brief The scene class that contains all geometry objects.
typedef struct Scene {
    uint32_t num_obj;
    Sphere** obj_list;
} Scene;

/// @brief Create a scene.
/// @param num_obj Number of objects in the scene.
/// @return The pointer to the scene.
Scene* scene_create(uint32_t num_obj);

/// @brief Destroy a scene.
/// @param scene The pointer to the scene.
void scene_destroy(Scene* scene);

/// @brief Add an object to the scene.
/// @param scene The scene object.
/// @param obj The object to be added.
/// @param index The index of the object.
void scene_add_object(Scene* scene, Sphere* obj, uint32_t index);

/// @brief Clear all objects in the scene.
/// @param scene The scene object.
void scene_clear_objects(Scene* scene);

/// @brief Test if a ray intersects with a scene.
/// @param scene The scene object.
/// @param ray The ray.
/// @param t_min The minimum t value.
/// @param t_max The maximum t value.
/// @param interaction The interaction record.
/// @return True if the ray intersects with the scene.
bool scene_hit(Scene const* scene, Ray const* ray, Float t_min, Float t_max, Interaction* interaction);

#endif // !_CS100_RAY_TRACING_SCENE_H_
