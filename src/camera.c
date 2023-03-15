/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of camera, which generates camera rays.
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

#include "camera.h"

#include <assert.h>
#include <stdlib.h>

#include "math-utils.h"

Camera* camera_create(Point3f look_from, Point3f look_to, Vector3f ref_up, Float y_field_of_view, Float focal_length, Float aspect_ratio) {
    Camera* camera = (Camera*)malloc(sizeof(Camera));
    assert(camera != NULL);

    camera->look_from = look_from;
    camera->look_to = look_to;
    camera->ref_up = ref_up;

    camera->y_field_of_view = y_field_of_view;
    camera->focal_length = focal_length;
    camera->aspect_ratio = aspect_ratio;

    // These vectors are properties that defines the position and the rotation of a camera.
    camera->look_front = vector3_unit(vector3_sub(camera->look_to, camera->look_from));
    camera->look_right = vector3_unit(vector3_cross(camera->look_front, camera->ref_up));
    camera->look_up = vector3_cross(camera->look_right, camera->look_front);

    // There vectors help for shooting a camera ray.
    camera->vertical = vector3_scalar_mul(camera->look_up, tan(deg_to_rad(camera->y_field_of_view / (Float)2.0)) * camera->focal_length);
    camera->horizontal = vector3_scalar_mul(camera->look_right, vector3_norm(camera->vertical) * camera->aspect_ratio);

    return camera;
}

void camera_destroy(Camera* camera) {
    assert(camera != NULL);

    free(camera);
}

void camera_set_film(Camera* camera, Film* film) {
    assert(camera != NULL);
    assert(film != NULL);

    camera->film = film;
}

void camera_set_pixel(Camera const* camera, uint32_t i, uint32_t j, Color3f color) {
    assert(camera->film != NULL);

    film_set_pixel(camera->film, i, j, color);
}

Ray camera_generate_ray(Camera const* camera, uint32_t i, uint32_t j) {
    assert(camera->film != NULL);

    // That is, instead of shooting ray to the corner of the pixel (i, j),
    // we shoot ray to the center of the pixel (i + 0.5, j + 0.5);
    Float u = (2.0 * ((Float)i + 0.5) / (Float)camera->film->width) - 1.0;
    Float v = (2.0 * ((Float)j + 0.5) / (Float)camera->film->height) - 1.0;

    Point3f origin = camera->look_from;
    Vector3f direction = vector3_add(vector3_add(vector3_scalar_mul(camera->horizontal, u), vector3_scalar_mul(camera->vertical, v)), vector3_scalar_mul(camera->look_front, camera->focal_length));

    return (Ray){ origin, direction };
}
