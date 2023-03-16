/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of arguments that need to be parsed.
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

#ifndef _CS100_RAY_TRACING_UTILS_ARG_PARSER_HPP_
#define _CS100_RAY_TRACING_UTILS_ARG_PARSER_HPP_

#include <args.hxx>
#include <string>

#include "common.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

/// @brief The arguments parsed required from command line.
struct Arguments {
    uint32_t image_width;
    uint32_t image_height;
    uint32_t spp;
    uint32_t ray_tracing_depth;
    std::string output_file_path;
    std::string config_file_path;
};

/// @brief Parse the arguments from command line.
/// @param argc The number of arguments.
/// @param argv The arguments.
/// @return The parsed arguments.
Arguments parse_args(int argc, char** argv);

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_UTILS_ARG_PARSER_HPP_
