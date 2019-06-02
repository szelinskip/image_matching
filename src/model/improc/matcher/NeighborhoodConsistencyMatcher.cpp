#include "NeighborhoodConsistencyMatcher.hpp"

namespace model {
namespace improc {
namespace matcher {

NeighborhoodConsistencyMatcher::NeighborhoodConsistencyMatcher(algorithm::NeighborhoodConsistency&& algo)
    : algo(std::move(algo))
{
}

MatchingPointsPairs NeighborhoodConsistencyMatcher::matchPoints(const MatchingPointsPairs& pointsPairs)
{
    return algo.filterConsistentPairs(pointsPairs);
}

} // namespace matcher
} // namespace improc
} // namespace model
