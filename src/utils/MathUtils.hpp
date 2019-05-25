#pragma once

#include <cstdint>
#include <vector>

namespace utils {

double euclideanDistance(const std::vector<double>& first, const std::vector<double>& second);
double euclideanDistance(const std::vector<int32_t>& first, const std::vector<int32_t>& second);

} // namespace utils
