#include "MathUtils.hpp"

#include <cmath>

namespace utils {
namespace math {

double euclideanDistance(const std::vector<double>& first, const std::vector<double>& second)
{
    // TODO: use library for linear algebra
    // assumption first.size() == second.size()

    double acc = 0.0;
    for(auto i = 0u; i < first.size(); i++)
    {
        double tmp = (first[i] - second[i]) * (first[i] - second[i]);
        acc += tmp;
    }
    return std::sqrt(acc);
}

double euclideanDistance(const std::vector<int32_t>& first, const std::vector<int32_t>& second)
{
    // TODO: use library for linear algebra
    // assumption first.size() == second.size()

    double acc = 0.0;
    for(auto i = 0u; i < first.size(); i++)
    {
        double tmp = (first[i] - second[i]) * (first[i] - second[i]);
        acc += tmp;
    }
    return std::sqrt(acc);
}

double euclideanDistance(const helpers::Point& first, const helpers::Point& second)
{
    return std::sqrt((first.getX() - second.getX()) * (first.getX() - second.getX())
                     + (first.getY() - second.getY()) * (first.getY() - second.getY()));
}

} // namespace math
} // namespace utils
