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

#include <cstdio>
#include <filesystem>
#include <memory>
#include <string>

#include "geometry/scene.h"
#include "geometry/sphere.h"
#include "integrator.h"

int main(int argc, char** argv) {
    // TODO: replace by parsing command line arguments/configuration files.
    if (argc != 6) {
        std::printf("Usage: %s <image_width> <image_height> <sample_per_pixel> <ray_tracing_depth> <output_file_path>\n", argv[0]);
        return 1;
    }

    uint32_t image_width;
    try {
        image_width = std::stoul(argv[1]);
    }
    catch (std::exception const& e) {
        std::printf("%s. [Error] Invalid image_width, process terminate.\n", e.what());
        return 1;
    }

    uint32_t image_height;
    try {
        image_height = std::stoul(argv[2]);
    }
    catch (std::exception const& e) {
        std::printf("%s. [Error] Invalid image_height, process terminate.\n", e.what());
        return 1;
    }

    uint32_t spp;
    try {
        spp = std::stoul(argv[3]);
    }
    catch (std::exception const& e) {
        std::printf("%s. [Error] Invalid spp, process terminate.\n", e.what());
        return 1;
    }
    if (image_width > 2048 || image_height > 2048 || spp > 2048) {
        std::printf("[Error] The image is too large to create, process terminate.\n");
        return 1;
    }

    uint32_t ray_tracing_depth;
    try {
        ray_tracing_depth = std::stoul(argv[4]);
    }
    catch (std::exception const& e) {
        std::printf("%s. [Error] Invalid ray_tracing_depth, process terminate.\n", e.what());
        return 1;
    }

    std::string output_file_path{ argv[5] };
    auto parent_dir = std::filesystem::path{ output_file_path }.parent_path();
    if (!std::filesystem::exists(parent_dir)) {
        std::printf("[Error] The directory %s does not exist, process terminate.\n", parent_dir.c_str());
        return 1;
    }

    std::printf("The image size is %u x %u pixels, with %u spp.\n", image_width, image_height, spp);
    // Create the camera.
    auto film = std::make_shared<Film>(image_width, image_height);
    auto camera = std::make_shared<Camera>(
        Point3f{ 0.0, 0.0, 0.0 },
        Point3f{ 0.0, 0.0, -1.0 },
        Vector3f{ 0.0, 1.0, 0.0 },
        90.0_f,
        1.0_f,
        film->get_aspect_ratio());
    camera->set_film(film);

    // Create the scene.
    auto scene = std::make_shared<Scene>();
    scene->add_object(std::make_shared<Sphere>(Point3f{ 0.0, 0.0, -1.0 }, 0.5_f));
    scene->add_object(std::make_shared<Sphere>(Point3f{ 0.0, -100.5, -1.0 }, 100.0_f));

    // Render the image.
    Integrator integrator(spp, ray_tracing_depth);
    integrator.render(camera, scene);

    // Output the image.
    camera->get_film().save(output_file_path);
    std::printf("Image saving done!\n");

    return 0;
}