#include "MathUtils.hpp"

#include <cmath>

#include <Eigen/Dense>

namespace utils {
namespace math {

double euclideanDistance(const std::vector<double>& first, const std::vector<double>& second)
{
    // assumption first.size() == second.size()

    Eigen::Map<const Eigen::VectorXd> firstVec(first.data(), static_cast<int>(first.size()));
    Eigen::Map<const Eigen::VectorXd> secondVec(second.data(), static_cast<int>(second.size()));

    return (firstVec - secondVec).norm();
}

double euclideanDistance(const std::vector<int32_t>& first, const std::vector<int32_t>& second)
{
    // assumption first.size() == second.size()

    std::vector<double> firstAsDoubleVec(first.cbegin(), first.cend());
    std::vector<double> secondAsDoubleVec(second.cbegin(), second.cend());

    return euclideanDistance(firstAsDoubleVec, secondAsDoubleVec);
}

double euclideanDistance(const helpers::Point& first, const helpers::Point& second)
{
    return std::sqrt((first.getX() - second.getX()) * (first.getX() - second.getX())
                     + (first.getY() - second.getY()) * (first.getY() - second.getY()));
}

} // namespace math
} // namespace utils
