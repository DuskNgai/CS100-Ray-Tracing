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
#define _CRT_SECURE_NO_WARNINGS

#include "film.h"

#include <cassert>
#include <cinttypes>
#include <cstdlib>
#include <cstdio>

Film::Film(uint32_t width, uint32_t height)
    : width{ width }
    , height{ height }
    , pixels(width * height) {}

Float Film::get_aspect_ratio() {
    return static_cast<Float>(this->width) / static_cast<Float>(this->height);
}

uint32_t Film::get_width() const { return this->width; }
uint32_t Film::get_height() const { return this->height; }

Color3f Film::get_pixel(uint32_t i, uint32_t j) const {
    return this->pixels[this->get_pixel_index(i, j)];
}

void Film::set_pixel(uint32_t i, uint32_t j, Color3f const& color) {
    this->pixels[this->get_pixel_index(i, j)] = color;
}

void Film::save(std::string const& file_name) const {
    // TODO: using third library to output an image.
    FILE* fp{ std::fopen(file_name.c_str(), "w") };
    assert(fp != nullptr);

    std::fprintf(fp, "P3\n%" PRIu32 " %" PRIu32 "\n255\n", this->width, this->height);
    for (uint32_t j{ 0 }; j < this->height; ++j) {
        for (uint32_t i{ 0 }; i < this->width; ++i) {
            Color3f color{ this->get_pixel(i, j) };
            uint8_t r{ (uint8_t)(color.x * 255.0_f) };
            uint8_t g{ (uint8_t)(color.y * 255.0_f) };
            uint8_t b{ (uint8_t)(color.z * 255.0_f) };

            std::fprintf(fp, "%" PRIu8 " %" PRIu8 " %" PRIu8 "\n", r, g, b);
        }
    }

    std::fclose(fp);
}

uint32_t Film::get_pixel_index(uint32_t i, uint32_t j) const {
    return j * this->width + i;
}
