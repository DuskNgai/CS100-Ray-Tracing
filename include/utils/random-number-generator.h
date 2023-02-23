/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of a random number generator which uniformly generates a number in [0, 1).
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

#ifndef _CS100_RAY_TRACING_RANDOM_NUMBER_GENERATOR_H_
#define _CS100_RAY_TRACING_RANDOM_NUMBER_GENERATOR_H_

#include <random>

#include "math-utils.h"

/// @brief A random number generator which uniformly generates a number in [0, 1).
class RandomNumberGenerator {
private:
    std::mt19937_64 generator;
    std::uniform_real_distribution<Float> distribution;

public:
    RandomNumberGenerator();

    /// @brief Get a random number in [0, 1).
    Float operator()();
};

#endif // !_CS100_RAY_TRACING_RANDOM_NUMBER_GENERATOR_H_
