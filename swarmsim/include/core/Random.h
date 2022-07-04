#ifndef RANDOM_H
#define RANDOM_H

#pragma once
#include <random>

// inline std::mt19937 generator(std::random_device());
inline std::default_random_engine generator;

namespace SwarmSim {

namespace Util {

inline double randomInteger(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
};

inline double randomDouble(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
};

}  // namespace Util
}  // namespace SwarmSim

#endif