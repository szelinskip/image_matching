#include "ImageMatcher.hpp"

#include "MutualNearestNeighbor.hpp"
#include "NeighborhoodConsistency.hpp"
#include "RansacAlgo.hpp"
#include <improc/transformation/TransformationModelAffine.hpp>
#include <improc/transformation/TransformationModelPerspective.hpp>
#include <improc/transformation/MatrixData.hpp>

namespace model {
namespace improc {
namespace matcher {

ImageMatcher::ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB)
    : imageA(imageA)
    , imageB(imageB)
{
}

ImageMatcher::~ImageMatcher() = default;

MatchingPointsPairs ImageMatcher::matchImages(const uint32_t /*neighborhoodSize*/,
                                              const double /*neighborhoodConsistencyThreshold*/) const
{
    // TODO
    MutualNearestNeighbor mutualNearestNeighborAlgo;

    MatchingPointsPairs matchingPointsPairs =
        mutualNearestNeighborAlgo.matchImages(imageA, imageB);

//    NeighborhoodConsistency neighborhoodConsistency(neighborhoodConsistencyThreshold, neighborhoodSize);

//    matchingPointsPairs = neighborhoodConsistency.filterConsistentPairs(matchingPointsPairs);

    RansacAlgo<TransformationModelPerspective> ransac(100, 50, 4);

    MatrixData matrixData(matchingPointsPairs);

    std::pair<std::unique_ptr<TransformationModel>, MatrixData> modelConsensusPair = ransac.runRansac(matrixData);

    matchingPointsPairs = modelConsensusPair.second.getDataAsPointsPairsVec();

    return matchingPointsPairs;
}

} // namespace matcher
} // namespace improc
} // namespace model
