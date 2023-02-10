/*
 * CS100-Ray-Tracing for course recitation.
 * The entrypoint of the program.
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

// TODO: remove this after introducing CMake.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

#include "vec3.h"
#include "film.h"

int main() {
    // TODO: replace by parsing command line arguments/configuration files.
    uint32_t image_width = 0, image_height = 0;
    fprintf(stderr, "Image width you want: ");
    if (scanf("%u", &image_width) != 1) {
        fprintf(stderr, "Invalid image_width, process terminate.\n");
        return 1;
    }
    fprintf(stderr, "Image height you want: ");
    if (scanf("%u", &image_height) != 1) {
        fprintf(stderr, "Invalid image_width, process terminate.\n");
        return 1;
    }
    fprintf(stderr, "The image size is %u x %u pixels.\n", image_width, image_height);
    if (image_width > 2048 || image_height > 2048) {
        fprintf(stderr, "The image is too large to create, process terminate.\n");
        return 1;
    }

    // Render the image.
    printf("P3\n%u %u\n255\n", image_width, image_height);
    Film* film = film_create(image_width, image_height);
    for (uint32_t j = 0; j < image_height; ++j) {
        for (uint32_t i = 0; i < image_width; ++i) {
            fprintf(stderr, "\rScanlines remaining: %u ", image_height - j - 1); fflush(stderr);

            Color3 pixel_color = { (Float)i / (Float)(image_width - 1), (Float)(image_height - j - 1) / (Float)(image_height - 1), (Float)0.25 };
            film_set_pixel_color3(film, i, j, &pixel_color);
        }
    }
    fprintf(stderr, "\nRendering done, outputing image.\n");
    film_save(film);
    fprintf(stderr, "Done!\n");

    return 0;
}
