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

#include <stdint.h>

#include "vec3.h"

/// @brief A film is a 2D array of pixels.
typedef struct Film {
    uint32_t width;
    uint32_t height;
    Color3* pixels;
} Film;

/// @brief Create a new film.
/// @param width The width of the film.
/// @param height The height of the film.
/// @return A pointer to the new film.
Film* film_create(uint32_t width, uint32_t height);

/// @brief Destroy a film.
/// @param film The film to destroy.
void film_destroy(Film* film);

/// @brief Get the aspect ratio of a film.
/// @param film The film to get the aspect ratio of.
/// @return The aspect ratio of the film.
Float film_get_aspect_ratio(Film const* film);

/// @brief Get the color of a pixel.
/// @param film The film to get the pixel of.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @return The color of the pixel.
Color3 film_get_pixel_color3(Film const* film, uint32_t i, uint32_t j);

/// @brief Set the color of a pixel.
/// @param film The film to set the pixel of.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @param color The color of the pixel.
void film_set_pixel_color3(Film* film, uint32_t i, uint32_t j, Color3 color);

/// @brief Set the color of a pixel.
/// @param film The film to set the pixel of.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @param r The red component of the pixel.
/// @param g The green component of the pixel.
/// @param b The blue component of the pixel.
void film_set_pixel_3f(Film* film, uint32_t i, uint32_t j, Float r, Float g, Float b);

/// @brief Save a film to a file.
/// @param film The film to save.
void film_save(Film const* film);

#endif // !_CS100_RAY_TRACING_FILM_H_
