#ifndef _CS100_RAY_TRACING_RANDOM_NUMBER_GENERATOR_H_
#define _CS100_RAY_TRACING_RANDOM_NUMBER_GENERATOR_H_

#include <random>

#include "math-utils.h"

/// @brief A random number generator.
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
