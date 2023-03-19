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

#include <cinttypes>
#include <cstdio>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "geometry/geometry.h"
#include "integrator.h"
#include "material/material.h"
#include "utils/arg-parser.h"
#include "utils/timer.h"

using namespace CS100;

int main(int argc, char** argv) {
    auto args{ parse_args(argc, argv) };

    std::printf(
        "The image size is %" PRIu32 " x %" PRIu32 " pixels, with %" PRIu32 " spp, depth of each ray is %" PRIu32 ".\n",
        args.image_width, args.image_height, args.spp, args.ray_tracing_depth);

    nlohmann::json config = nlohmann::json::parse(std::ifstream{ args.config_file_path });

    // Create the camera.
    auto camera{ Camera::create(config.at("Camera")) };
    camera->set_film(std::make_unique<Film>(args.image_width, args.image_height));

    // Create the scene.
    auto scene{ Scene::create(config.at("Scene")) };

    // Render the image.
    Timer timer;
    timer.start();
    Integrator integrator{ args.spp, args.ray_tracing_depth };
    integrator.render(scene, camera);
    timer.stop();
    std::printf("Elapsed time: %" PRIi64 " ms.\n", timer.get_elapsed_time());

    // Output the image.
    camera->get_film().save(args.output_file_path);
    std::printf("Image saving done!\n");

    return 0;
}
