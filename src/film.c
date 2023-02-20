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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Film* film_create(uint32_t width, uint32_t height) {
    Film* film = (Film*)malloc(sizeof(Film));
    film->width = width;
    film->height = height;
    film->pixels = (Color3*)malloc(sizeof(Color3) * width * height);
    return film;
}

void film_destroy(Film* film) {
    ASSERT(film != NULL);

    free(film->pixels);
    free(film);
}

Float film_get_aspect_ratio(Film const* film) {
    ASSERT(film != NULL);

    return (Float)film->width / (Float)film->height;
}

static uint32_t film_get_pixel_index(Film const* film, uint32_t i, uint32_t j) {
    ASSERT(film != NULL);

    return j * film->width + i;
}

Color3 film_get_pixel_color3(Film const* film, uint32_t i, uint32_t j) {
    ASSERT(film != NULL);

    return film->pixels[film_get_pixel_index(film, i, j)];
}

void film_set_pixel_color3(Film* film, uint32_t i, uint32_t j, Color3 color) {
    ASSERT(film != NULL);

    film->pixels[film_get_pixel_index(film, i, j)] = color;
}

void film_set_pixel_3f(Film* film, uint32_t i, uint32_t j, Float r, Float g, Float b) {
    ASSERT(film != NULL);

    film_set_pixel_color3(film, i, j, (Color3){ r, g, b });
}

void film_save(Film const* film) {
    ASSERT(film != NULL);

    for (uint32_t j = 0; j < film->height; ++j) {
        for (uint32_t i = 0; i < film->width; ++i) {
            Color3 color = film_get_pixel_color3(film, i, j);
            uint8_t r = (uint8_t)(color.x * 255.0);
            uint8_t g = (uint8_t)(color.y * 255.0);
            uint8_t b = (uint8_t)(color.z * 255.0);

            printf("%u %u %u\n", r, g, b);
        }
    }
}