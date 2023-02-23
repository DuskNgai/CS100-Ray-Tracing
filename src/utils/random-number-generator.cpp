#include "utils/random-number-generator.h"

RandomNumberGenerator::RandomNumberGenerator()
    : generator{std::random_device{}()}
    , distribution{static_cast<Float>(0), static_cast<Float>(1)} {}

Float RandomNumberGenerator::operator()() {
    return distribution(generator);
}
