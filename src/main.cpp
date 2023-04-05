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

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "integrator.h"

int main(int argc, char** argv) {
    // Parse the command line arguments.
    // TODO: using third library to parse command line arguments.
    if (argc != 4) {
        std::fprintf(stderr, "[Error] Invalid command line arguments.\n");
        std::fprintf(stderr, "Usage: %s <image_width> <image_height> <image_path>", argv[0]);
        return 1;
    }

    // TODO: Fix exception safe in C++.
    uint32_t image_width{ std::strtoul(argv[1], nullptr, 10) };
    uint32_t image_height{ std::strtoul(argv[2], nullptr, 10) };
    char const* image_path{ argv[3] };

    if (image_width > 2048 || image_height > 2048) {
        std::fprintf(stderr, "[Error] Image size too large, process terminate\n.");
        return 1;
    }

    std::printf("The image size is %" PRIu32 " x %" PRIu32 " pixels.\n", image_width, image_height);

    // Create a film and a camera.
    Film* film{ new Film{ image_width, image_height } };
    Camera* camera{ new Camera{
        Point3f{ 0.0f, 0.0f, 0.0f },
        Point3f{ 0.0f, 0.0f, -1.0f },
        Vector3f{ 0.0f, 1.0f, 0.0f },
        90.0_f,
        1.0_f,
        film->get_aspect_ratio()} };
    camera->set_film(film);

    // Render the image.
    render(camera);

    camera->get_film().save(image_path);
    std::printf("Image saving done!\n");

    delete camera;
    delete film;
    return 0;
}
