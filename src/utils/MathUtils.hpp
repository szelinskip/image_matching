#pragma once

#include <cstdint>
#include <vector>

#include <helpers/Point.hpp>

namespace utils {
namespace math {

double euclideanDistance(const std::vector<double>& first, const std::vector<double>& second);
double euclideanDistance(const std::vector<int32_t>& first, const std::vector<int32_t>& second);
double euclideanDistance(const helpers::Point& first, const helpers::Point& second);

} // namespace math
} // namespace utils
