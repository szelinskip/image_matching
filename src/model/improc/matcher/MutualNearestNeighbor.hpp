#pragma once

#include <helpers/Point.hpp>
#include <improc/ImageDescription.hpp>

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class MutualNearestNeighbor
{
public:
    MatchingPointsPairs matchImages(const ImageDescription& imageA, const ImageDescription& imageB) const;
};

} // namespace matcher
} // namespace improc
} // namespace model
