#include "ImageMatcher.hpp"

#include "AffineTransformation.hpp"
#include "PerspectiveTransformation.hpp"
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

Eigen::Matrix2Xd ImageMatcher::makePointsMatrix(const Points& points) const
{
    Eigen::Matrix2Xd pointsMatrix;
    for(const auto& point : points)
    {
        Eigen::Vector2d pointVec(point.getX(), point.getY());
        pointsMatrix.conservativeResize(Eigen::NoChange, pointsMatrix.cols() + 1);
        pointsMatrix.col(pointsMatrix.cols() - 1) = std::move(pointVec);
    }

    return pointsMatrix;
}

} // namespace matcher
} // namespace improc
} // namespace model
