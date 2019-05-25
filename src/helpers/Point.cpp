#include "Point.hpp"

#include <cmath>

namespace helpers {

Point::Point() = default;

Point::Point(const double xDim, const double yDim)
    : xDim(xDim)
    , yDim(yDim)
{
}

bool Point::operator==(const Point& other) const
{
    return std::abs(xDim - other.xDim) < 0.0001 && std::abs(yDim - other.yDim) < 0.0001;
}

Point::~Point() = default;
Point::Point(const Point&) = default;
Point& Point::operator=(const Point&) = default;
Point::Point(Point&&) = default;
Point& Point::operator=(Point&&) = default;

double& Point::X()
{
    return xDim;
}

double& Point::Y()
{
    return yDim;
}

} // namespace helpers
