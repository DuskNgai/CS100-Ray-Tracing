/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of a film, which stores a 2D array of pixels.
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

#include "film.h"

#include <algorithm>
#include <fstream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

CS100_RAY_TRACING_NAMESPACE_BEGIN

Film::Film(uint32_t width, uint32_t height)
    : width{ width }
    , height{ height }
    , pixels(width * height) {}

Float Film::get_aspect_ratio() const {
    return static_cast<Float>(this->width) / static_cast<Float>(this->height);
}

Color3f Film::get_pixel(uint32_t i, uint32_t j) const {
    return this->pixels[this->get_pixel_index(i, j)];
}

void Film::set_pixel(uint32_t i, uint32_t j, Color3f const& color) {
    this->pixels[this->get_pixel_index(i, j)] = color;
}

void Film::save(std::filesystem::path const& file_name) const {
    std::vector<uint8_t> buffer;
    buffer.reserve(this->pixels.size() * 3);

    /// @brief Gamma correction.
    auto gamma_correction = [](Float x, Float gamma = 2.0_f) {
        x = std::clamp(x, 0.0_f, 1.0_f);
        return static_cast<uint8_t>(std::pow(x, 1.0_f / gamma) * 255.0_f);
    };

    for (auto const& color : this->pixels) {
        buffer.emplace_back(gamma_correction(color.x()));
        buffer.emplace_back(gamma_correction(color.y()));
        buffer.emplace_back(gamma_correction(color.z()));
    }

    stbi_flip_vertically_on_write(true);
    stbi_write_png(file_name.string().c_str(), this->width, this->height, 3, buffer.data(), 0);
}

uint32_t Film::get_pixel_index(uint32_t i, uint32_t j) const {
    return j * this->width + i;
}

CS100_RAY_TRACING_NAMESPACE_END
