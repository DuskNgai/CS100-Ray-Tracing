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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "film.h"

#define pow(x, y)         \
    _Generic((x),         \
        float: powf,      \
        double: pow,      \
        long double: powl \
    )(x, y)

Film* film_create(uint32_t width, uint32_t height) {
    Film* film = (Film*)malloc(sizeof(Film));
    film->width = width;
    film->height = height;
    film->pixels = (Color3*)malloc(sizeof(Color3) * width * height);
    return film;
}

void film_destroy(Film* film) {
    free(film->pixels);
    free(film);
}

void film_set_pixel_color3(Film* film, uint32_t x, uint32_t y, Color3 const* color) {
    film->pixels[y * film->width + x] = *color;
}

void film_set_pixel_3f(Film* film, uint32_t x, uint32_t y, Float r, Float g, Float b) {
    film_set_pixel_color3(film, x, y, &(Color3){r, g, b});
}

static uint8_t film_gamma_correction(Float x) {
    if (x > (Float)1.0) x = (Float)1.0;
    if (x < (Float)0.0) x = (Float)0.0;
    return (uint8_t)(pow(x, (Float)1.0 / (Float)2.2) * (Float)255.0);
}

void film_save(Film const* film) {
    for (uint32_t j = 0; j < film->height; ++j) {
        for (uint32_t i = 0; i < film->width; ++i) {
            uint8_t r = film_gamma_correction(film->pixels[j * film->width + i].x);
            uint8_t g = film_gamma_correction(film->pixels[j * film->width + i].y);
            uint8_t b = film_gamma_correction(film->pixels[j * film->width + i].z);

            printf("%u %u %u\n", r, g, b);
        }
    }
}
