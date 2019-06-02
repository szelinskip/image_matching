#include "ImageMatcher.hpp"

#include <chrono>

#include "RansacMatcher.hpp"
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

MatchingResult ImageMatcher::matchImages() const
{
    MatchingResult result;
    result.imageACharacteristicsPointsNum = static_cast<uint32_t>(imageA.getCharacteristicPoints().size());
    result.imageBCharacteristicsPointsNum = static_cast<uint32_t>(imageB.getCharacteristicPoints().size());
    MutualNearestNeighbor mutualNearestNeighborAlgo;

    auto start = std::chrono::steady_clock::now();

    MatchingPointsPairs mutualNeighborhoodMatchingPairs =
        mutualNearestNeighborAlgo.matchImages(imageA, imageB);
    MatchingPointsPairs finalMatchingPairs = matcher->matchPoints(mutualNeighborhoodMatchingPairs);

    auto stop = std::chrono::steady_clock::now();

    result.elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    result.mutualNeighborhoodPointsPairs = static_cast<uint32_t>(mutualNeighborhoodMatchingPairs.size());
    result.finalNumOfMatchingPointsPairs = static_cast<uint32_t>(finalMatchingPairs.size());
    result.finalMatchingPairs = std::move(finalMatchingPairs);

    RansacMatcher* ransacMatcher = dynamic_cast<RansacMatcher*>(matcher.get());
    if(ransacMatcher != nullptr)
    {
        result.ransacItersNum = ransacMatcher->getItersNum();
    }

    return result;
}

} // namespace matcher
} // namespace improc
} // namespace model
