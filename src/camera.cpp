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

#include "math-utils.h"

Camera::Camera(Point3f const& look_from, Point3f const& look_to, Vector3f const& ref_up, Float y_field_of_view, Float focal_length, std::shared_ptr<Film> film)
    : look_from(look_from), look_to(look_to), y_field_of_view(y_field_of_view), focal_length(focal_length) {
    this->look_front = (this->look_to - this->look_from).unit();
    this->look_right = cross(this->look_front, ref_up).unit();
    this->look_up = cross(this->look_right, this->look_front);

    this->horizontal = Vector3f{ 0.0, 0.0, 0.0 };
    this->vertical = this->look_up * std::tan(deg_to_rad(this->y_field_of_view / 2.0_f)) * this->focal_length;

    this->set_film(film);
}

void Camera::set_film(std::shared_ptr<Film> film) {
    this->film = film;
    Float aspect_ratio = film->get_aspect_ratio();
    this->horizontal = this->look_right * this->vertical.norm() * aspect_ratio;
}

Film const& Camera::get_film() const {
    return *this->film;
}

void Camera::set_pixel(uint32_t i, uint32_t j, Color3f const& color) const {
    this->film->set_pixel(i, j, color);
}

Ray Camera::generate_ray(uint32_t i, uint32_t j, RandomNumberGenerator& rng) const {
    // Shoot ray to the center of the pixel.
    Float u = (2.0_f * (static_cast<Float>(i) + rng()) / static_cast<Float>(this->film->width)) - 1.0_f;
    Float v = (2.0_f * (static_cast<Float>(j) + rng()) / static_cast<Float>(this->film->height)) - 1.0_f;

    Point3f origin = this->look_from;
    Vector3f direction = this->horizontal * u + this->vertical * v + this->look_front * this->focal_length;

    return { origin, direction };
}
