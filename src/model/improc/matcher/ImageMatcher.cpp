#include "ImageMatcher.hpp"

#include "MutualNearestNeighbor.hpp"

namespace model {
namespace improc {
namespace matcher {

ImageMatcher::ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB)
    : imageA(imageA)
    , imageB(imageB)
{
}

ImageMatcher::~ImageMatcher() = default;

MatchingPointsPairs ImageMatcher::matchImages() const
{
    // TODO
    MutualNearestNeighbor mutualNearestNeighborAlgo;

    return mutualNearestNeighborAlgo.matchImages(imageA, imageB);
}

} // namespace matcher
} // namespace improc
} // namespace model
