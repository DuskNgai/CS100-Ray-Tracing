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

#include <cassert>
#include <cstdlib>

#include "math-utils.h"

Camera::Camera(Point3f look_from, Point3f look_to, Vector3f ref_up, Float y_field_of_view, Float focal_length, Float aspect_ratio)
    : look_from{ look_from }
    , look_to{ look_to }
    , ref_up{ ref_up }
    , y_field_of_view{ y_field_of_view }
    , focal_length{ focal_length }
    , aspect_ratio{ aspect_ratio }
    , look_front{ vector3_unit(vector3_sub(look_to, look_from)) }
    , look_right{ vector3_unit(vector3_cross(look_front, ref_up)) }
    , look_up{ vector3_cross(look_right, look_front) }
    , vertical{ vector3_scalar_mul(look_up, std::tan(deg_to_rad(y_field_of_view / 2.0_f)) * focal_length) }
    , horizontal{ vector3_scalar_mul(look_right, vector3_norm(vertical) * aspect_ratio) } {}

Film const& Camera::get_film() const { return *this->film; }

void Camera::set_film(Film* film) {
    assert(film != nullptr);

    this->film = film;
}

void Camera::set_pixel(uint32_t i, uint32_t j, Color3f const& color) const {
    this->film->set_pixel(i, j, color);
}

Ray Camera::generate_ray(uint32_t i, uint32_t j) const {
    assert(this->film != nullptr);

    // That is, instead of shooting ray to the corner of the pixel (i, j),
    // we shoot ray to the center of the pixel (i + 0.5, j + 0.5);
    Float u{ (2.0_f * (static_cast<Float>(i) + 0.5_f) / static_cast<Float>(this->film->get_width())) - 1.0_f };
    Float v{ (2.0_f * (static_cast<Float>(j) + 0.5_f) / static_cast<Float>(this->film->get_height())) - 1.0_f };

    Point3f origin{ this->look_from };
    Vector3f direction{ vector3_add(vector3_add(vector3_scalar_mul(this->horizontal, u), vector3_scalar_mul(this->vertical, v)), vector3_scalar_mul(this->look_front, this->focal_length)) };

    return { origin, direction };
}
