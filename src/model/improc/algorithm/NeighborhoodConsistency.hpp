#pragma once

#include <cstdint>
#include <set>
#include <vector>

#include <helpers/Point.hpp>

namespace model {
namespace improc {
namespace algorithm {

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class NeighborhoodConsistency
{
public:
    NeighborhoodConsistency() = delete;

    NeighborhoodConsistency(const double consistencyThreshold, const uint32_t neighborhoodSize);
    ~NeighborhoodConsistency();
    NeighborhoodConsistency(const NeighborhoodConsistency&);
    NeighborhoodConsistency& operator=(const NeighborhoodConsistency&);
    NeighborhoodConsistency(NeighborhoodConsistency&&);
    NeighborhoodConsistency& operator=(NeighborhoodConsistency&&);

    MatchingPointsPairs filterConsistentPairs(const MatchingPointsPairs& matchingPointsPairs);

private:
    std::vector<uint32_t> getPointNeighborhoodIndices(const Point& point, const std::vector<Point>& allPoints);

    double consistencyThreshold;
    uint32_t neighborhoodSize;
};

} // namespace algorithm
} // namespace improc
} // namespace model
