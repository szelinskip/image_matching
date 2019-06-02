#include "ImageMatcher.hpp"

#include "MutualNearestNeighbor.hpp"

namespace model {
namespace improc {
namespace matcher {

ImageMatcher::ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB,
                           std::unique_ptr<Matcher>&& matcher)
    : imageA(imageA)
    , imageB(imageB)
    , matcher(std::move(matcher))
{
}

ImageMatcher::~ImageMatcher() = default;

MatchingPointsPairs ImageMatcher::matchImages() const
{
    MutualNearestNeighbor mutualNearestNeighborAlgo;

    MatchingPointsPairs matchingPointsPairs =
        mutualNearestNeighborAlgo.matchImages(imageA, imageB);

    return matcher->matchPoints(matchingPointsPairs);
}

} // namespace matcher
} // namespace improc
} // namespace model
