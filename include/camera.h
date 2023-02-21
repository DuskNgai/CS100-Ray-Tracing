/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of camera, which generates camera rays.
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

#ifndef _CS100_RAY_TRACING_CAMERA_H_
#define _CS100_RAY_TRACING_CAMERA_H_

#include "film.h"
#include "ray.h"

/// @brief A camera that generates rays whose up direction is always positive y axis.
typedef struct Camera {
    Point3 look_from;
    Point3 look_to;

    Float y_field_of_view;
    Float focal_length;

    Vec3 look_front;
    Vec3 look_up;
    Vec3 look_right;

    Vec3 horizontal;
    Vec3 vertical;

    Film* film;
} Camera;

/// @brief Create a camera.
/// @param look_from The position of the camera.
/// @param look_to The position of the object that the camera looks at.
/// @param ref_up The reference up vector of the camera.
/// @param y_field_of_view The y field of view of the camera, in degrees.
/// @param focal_length The focal length of the camera.
/// @return The created camera.
Camera* camera_create(Point3 look_from, Point3 look_to, Vec3 ref_up, Float y_field_of_view, Float focal_length);

/// @brief Destroy a camera.
/// @param camera The camera to destroy.
void camera_destroy(Camera* camera);

/// @brief Set the film of the camera, change the aspect radio of camera.
/// @param camera The camera.
/// @param film The film.
void camera_set_film(Camera* camera, Film* film);

/// @brief Set the pixel of the camera.
/// @param camera The camera.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @param color The color of the pixel.
void camera_set_pixel_color3(Camera* camera, uint32_t i, uint32_t j, Color3 color);

/// @brief Generate a ray from the camera.
/// @param camera The camera.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @return The generated ray.
Ray camera_generate_ray(Camera* camera, uint32_t i, uint32_t j);

#endif // !_CS100_RAY_TRACING_CAMERA_H_
