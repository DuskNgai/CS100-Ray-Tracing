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

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

Scene* scene_create(uint32_t num_obj) {
    Scene* scene = (Scene*)malloc(sizeof(Scene));
    scene->num_obj = num_obj;
    scene->obj_list = (Sphere**)malloc(sizeof(Sphere*) * num_obj);
    return scene;
}

void scene_destroy(Scene* scene) {
    assert(scene != NULL);

    scene_clear_objects(scene);
    free(scene->obj_list);
    free(scene);
}

void scene_add_object(Scene* scene, Sphere* obj, uint32_t index) {
    assert(scene != NULL);

    scene->obj_list[index] = obj;
}

void scene_clear_objects(Scene* scene) {
    assert(scene != NULL);

    for (uint32_t i = 0; i < scene->num_obj; ++i) {
        free(scene->obj_list[i]);
    }
}

bool scene_hit(Scene const* scene, Ray const* ray, Float t_min, Float t_max, Interaction* interaction) {
    assert(scene != NULL);
    assert(ray != NULL);

    bool hit_anything = false;
    Float closest_so_far = t_max;
    Interaction local_interaction;
    for (uint32_t i = 0; i < scene->num_obj; ++i) {
        // Update to the closest interaction.
        if (sphere_hit(scene->obj_list[i], ray, t_min, closest_so_far, &local_interaction)) {
            hit_anything = true;
            closest_so_far = local_interaction.t;
            *interaction = local_interaction;
        }
    }
    return hit_anything;
}