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

#include <memory>

#include "film.h"
#include "ray.h"
#include "utils/random-number-generator.h"

/// @brief A camera that generates rays whose up direction is always positive y axis.
class Camera {
private:
    Point3f look_from;
    Point3f look_to;

    Float y_field_of_view;
    Float focal_length;
    Float aspect_ratio;

    Vector3f look_front;
    Vector3f look_up;
    Vector3f look_right;

    Vector3f horizontal;
    Vector3f vertical;

    std::shared_ptr<Film> film;

public:
    /// @brief Create a camera.
    /// @param look_from The position of the camera.
    /// @param look_to The position of the object that the camera looks at.
    /// @param ref_up The reference up vector of the camera.
    /// @param y_field_of_view The y field of view of the camera, in degrees.
    /// @param focal_length The focal length of the camera.
    /// @param aspect_ratio The aspect ratio of the camera.
    Camera(Point3f const& look_from, Point3f const& look_to, Vector3f const& ref_up, Float y_field_of_view, Float focal_length, Float aspect_ratio);
    Camera(Camera const& other) = delete;
    Camera(Camera&& other) = delete;
    Camera& operator=(Camera const& other) = delete;
    Camera& operator=(Camera&& other) = delete;
    ~Camera() = default;

    /// @brief Set the film of the camera, change the aspect radio of camera.
    /// @param film The film.
    void set_film(std::shared_ptr<Film> const& film);

    /// @brief Get the film of the camera.
    /// @param film The film.
    Film const& get_film() const;

    /// @brief Set the pixel color of the film.
    /// @param i The i coordinate of the pixel.
    /// @param j The j coordinate of the pixel.
    /// @param color The color of the pixel.
    void set_pixel(uint32_t i, uint32_t j, Color3f const& color) const;

    /// @brief Generate a ray from the camera.
    /// @param i The i coordinate of the pixel.
    /// @param j The j coordinate of the pixel.
    /// @param rng The random number generator.
    /// @return The generated ray.
    Ray generate_ray(uint32_t i, uint32_t j, RandomNumberGenerator& rng) const;
};

#endif // !_CS100_RAY_TRACING_CAMERA_H_
