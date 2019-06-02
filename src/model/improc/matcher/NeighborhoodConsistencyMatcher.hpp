#pragma once

#include <cstdint>
#include <utility>
#include <vector>

#include <improc/algorithm/NeighborhoodConsistency.hpp>
#include <helpers/Point.hpp>
#include "Matcher.hpp"

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using Points = std::vector<Point>;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class NeighborhoodConsistencyMatcher : public Matcher
{
public:
    NeighborhoodConsistencyMatcher(algorithm::NeighborhoodConsistency&& algo);

    virtual MatchingPointsPairs matchPoints(const MatchingPointsPairs& pointsPairs) override;

private:
    algorithm::NeighborhoodConsistency algo;
};

} // namespace matcher
} // namespace improc
} // namespace model
