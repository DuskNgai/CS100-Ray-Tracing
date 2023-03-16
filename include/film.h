/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of a film, which stores a 2D array of pixels.
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

#ifndef _CS100_RAY_TRACING_FILM_H_
#define _CS100_RAY_TRACING_FILM_H_

#include <string>
#include <vector>

#include "vector3.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

/// @brief A film is a 2D array of pixels.
struct Film {
    uint32_t width;
    uint32_t height;
    std::vector<Color3f> pixels;

    /// @brief Create a new film.
    /// @param width The width of the film.
    /// @param height The height of the film.
    Film(uint32_t width, uint32_t height);
    Film(Film const&) = delete;
    Film(Film&&) = delete;
    Film& operator=(Film const&) = delete;
    Film& operator=(Film&&) = delete;
    ~Film() = default;

    /// @brief Get the aspect ratio of a film.
    /// @return The aspect ratio of the film.
    Float get_aspect_ratio() const;

    /// @brief Get the color of a pixel.
    /// @param i The i coordinate of the pixel.
    /// @param j The j coordinate of the pixel.
    /// @return The color of the pixel.
    Color3f get_pixel(uint32_t i, uint32_t j) const;

    /// @brief Set the color of a pixel.
    /// @param i The i coordinate of the pixel.
    /// @param j The j coordinate of the pixel.
    /// @return The color of the pixel.
    void set_pixel(uint32_t i, uint32_t j, Color3f const& color);

    /// @brief Save a film to a file.
    /// @param file_name The file name to store the image.
    void save(std::string const& file_name) const;

private:
    /// @brief Get the index of 2 dimensional array.
    /// @param i The i coordinate of the pixel.
    /// @param j The j coordinate of the pixel.
    /// @return The index of the pixel (i, j).
    uint32_t get_pixel_index(uint32_t i, uint32_t j) const;
};

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_FILM_H_
