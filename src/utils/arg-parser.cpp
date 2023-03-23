/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of arguments that need to be parsed.
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

#include "utils/arg-parser.h"

#include <cstdlib>

CS100_RAY_TRACING_NAMESPACE_BEGIN

Arguments parse_args(int argc, char** argv) {
    args::ArgumentParser parser{ "A simple ray tracing for CS100 recitation class." };

    args::HelpFlag help{ parser, "help", "Display this help menu.", { 'h', "help" } };

    args::Group defaulted{ parser, "This group of arguments has default value.", args::Group::Validators::DontCare };
    args::ValueFlag<uint32_t> width_flag{ defaulted, "WIDTH", "Resolution width of the output image, default to 960.", { "width" }, 960 };
    args::ValueFlag<uint32_t> height_flag{ defaulted, "HEIGHT", "Resolution height of the output image, default to 540.", { "height" }, 540 };
    args::ValueFlag<uint32_t> spp_flag{ defaulted, "SAMPLE_PER_PIXEL", "Number of samples per pixel, default to 100.", { "spp", "sample-per-pixels" }, 100 };
    args::ValueFlag<uint32_t> depth_flag{ defaulted, "RAY_TRACE_DEPTH", "The depth to tracing a ray, default to 50.", { "depth", "ray-tracing-depth" }, 50 };

    args::Group required{ parser, "This group of arguments is all required from command line.", args::Group::Validators::All };
    args::ValueFlag<std::string> output_path_flag{ required, "OUTPUT_PATH", "Path to the output image file.", { "output-path" } };
    args::ValueFlag<std::string> config_path_flag{ required, "CONFIG_PATH", "Path to the config file.", { "config-path" } };


    try {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Help&) {
        std::fprintf(stderr, "%s", parser.Help().c_str());
        std::exit(0);
    }
    catch (const args::ParseError& e) {
        std::fprintf(stderr, "%s\n", e.what());
        std::fprintf(stderr, "%s", parser.Help().c_str());
        std::exit(-1);
    }
    catch (const args::ValidationError& e) {
        std::fprintf(stderr, "%s\n", e.what());
        std::fprintf(stderr, "%s", parser.Help().c_str());
        std::exit(-2);
    }

    std::filesystem::path output_path{ args::get(output_path_flag) };
    if (output_path.parent_path().empty()) {
        output_path = std::filesystem::current_path() / output_path;
    }
    if (not std::filesystem::exists(output_path.parent_path())) {
        std::printf("[Error] The directory of the output file path %s does not exist, process terminate.\n", output_path.string().c_str());
        std::exit(-3);
    }

    std::filesystem::path config_path{ args::get(config_path_flag) };
    if (not std::filesystem::exists(config_path)) {
        std::printf("[Error] The config file path %s does not exist, process terminate.\n", config_path.string().c_str());
        std::exit(-3);
    }

    return {
        args::get(width_flag),
        args::get(height_flag),
        args::get(spp_flag),
        args::get(depth_flag),
        output_path,
        config_path,
    };
}

CS100_RAY_TRACING_NAMESPACE_END
