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

#include <stdlib.h>

#include "math-utils.h"

Camera* camera_create(Point3 look_from, Point3 look_to, Vec3 ref_up, Float y_field_of_view, Float focal_length) {
    Camera* camera = (Camera*)malloc(sizeof(Camera));

    camera->look_from = look_from;
    camera->look_to = look_to;

    camera->y_field_of_view = y_field_of_view;
    camera->focal_length = focal_length;

    camera->look_front = vec3_unit(vec3_sub(camera->look_to, camera->look_from));
    camera->look_right = vec3_unit(vec3_cross(camera->look_front, ref_up));
    camera->look_up = vec3_cross(camera->look_right, camera->look_front);

    camera->horizontal = (Vec3){ 0.0, 0.0, 0.0 };
    camera->vertical = vec3_scalar_mul(camera->look_up, tan(deg_to_rad(camera->y_field_of_view / (Float)2.0)) * camera->focal_length);

    camera->film = NULL;
    return camera;
}

void camera_destroy(Camera* camera) {
    free(camera);
}

void camera_set_film(Camera* camera, Film* film) {
    if (film == NULL)
        return;

    camera->film = film;
    Float aspect_ratio = film_get_aspect_ratio(film);
    camera->horizontal = vec3_scalar_mul(camera->look_right, vec3_norm(camera->vertical) * aspect_ratio);
}

void camera_set_pixel_color3(Camera* camera, uint32_t i, uint32_t j, Color3 color) {
    film_set_pixel_color3(camera->film, i, j, color);
}

Ray camera_generate_ray(Camera* camera, uint32_t i, uint32_t j) {
    Float u = ((Float)2.0 * (Float)i / (Float)(camera->film->width - 1)) - (Float)1.0;
    Float v = ((Float)2.0 * (Float)j / (Float)(camera->film->height - 1)) - (Float)1.0;

    Point3 origin = camera->look_from;
    Vec3 direction = vec3_add(vec3_add(vec3_scalar_mul(camera->horizontal, u), vec3_scalar_mul(camera->vertical, v)), vec3_scalar_mul(camera->look_front, camera->focal_length));

    return (Ray){ origin, direction };
}
