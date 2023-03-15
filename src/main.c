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

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "integrator.h"

int main(int argc, char** argv) {
    // Parse the command line arguments.
    // TODO: using third library to parse command line arguments.
    if (argc != 4) {
        fprintf(stderr, "[Error] Invalid command line arguments.\n");
        fprintf(stderr, "Usage: %s <image_width> <image_height> <image_path>", argv[0]);
        return 1;
    }

    // TODO: Fix exception safe in C++.
    uint32_t image_width = strtoul(argv[1], NULL, 10);
    uint32_t image_height = strtoul(argv[2], NULL, 10);
    char const* image_path = argv[3];

    if (image_width > 2048 || image_height > 2048) {
        fprintf(stderr, "[Error] Image size too large, process terminate\n.");
        return 1;
    }

    printf("The image size is %"PRIu32" x %"PRIu32" pixels.\n", image_width, image_height);

    // Create a film and a camera.
    Film* film = film_create(image_width, image_height);
    Camera* camera = camera_create(
        (Point3f){ 0.0f, 0.0f, 0.0f },
        (Point3f){ 0.0f, 0.0f, -1.0f },
        (Vector3f){ 0.0f, 1.0f, 0.0f },
        (Float)90.0,
        (Float)1.0,
        film_get_aspect_ratio(film));
    camera_set_film(camera, film);

    // Render the image.
    render(camera);

    film_save(camera->film, image_path);
    printf("Image saving done!\n");

    film_destroy(film);
    camera_destroy(camera);
    return 0;
}
