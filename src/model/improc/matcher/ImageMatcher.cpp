#include "ImageMatcher.hpp"

#include "MutualNearestNeighbor.hpp"
#include "NeighborhoodConsistency.hpp"

namespace model {
namespace improc {
namespace matcher {

ImageMatcher::ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB)
    : imageA(imageA)
    , imageB(imageB)
{
}

ImageMatcher::~ImageMatcher() = default;

MatchingPointsPairs ImageMatcher::matchImages(const uint32_t neighborhoodSize,
                                              const double neighborhoodConsistencyThreshold) const
{
    // TODO
    MutualNearestNeighbor mutualNearestNeighborAlgo;

    MatchingPointsPairs matchingPointsPairs =
        mutualNearestNeighborAlgo.matchImages(imageA, imageB);

    NeighborhoodConsistency neighborhoodConsistency(neighborhoodConsistencyThreshold, neighborhoodSize);

    matchingPointsPairs = neighborhoodConsistency.filterConsistentPairs(matchingPointsPairs);

    return matchingPointsPairs;
}

} // namespace matcher
} // namespace improc
} // namespace model
