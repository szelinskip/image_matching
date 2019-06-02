#include "MatcherFactory.hpp"

#include "NeighborhoodConsistencyMatcher.hpp"
#include "RansacMatcher.hpp"
#include <improc/algorithm/NeighborhoodConsistency.hpp>
#include <improc/algorithm/AffineTransformationRansac.hpp>
#include <improc/algorithm/PerspectiveTransformationRansac.hpp>
#include <improc/algorithm/RansacFactory.hpp>

namespace model {
namespace improc {
namespace matcher {

MatcherFactory::MatcherFactory() = default;
MatcherFactory::~MatcherFactory() = default;

std::unique_ptr<Matcher> MatcherFactory::make(const ImageMatchingParams& params)
{
    if(params.matchingMethod == "Neighborhood consistency")
    {
        return std::make_unique<NeighborhoodConsistencyMatcher>(algorithm::NeighborhoodConsistency(
            params.neighborhoodConsistencyThreshold, params.neighborhoodSize));
    }

    if(params.matchingMethod.find("RANSAC") != std::string::npos)
    {
        algorithm::RansacFactory ransacFactory;
        algorithm::RansacParams ransacParams;
        ransacParams.ransacMethod = params.matchingMethod;
        ransacParams.errorThreshold = params.errorThreshold;
        ransacParams.itersNum = params.itersNum;
        ransacParams.distanceHeuristicEnabled = params.distanceHeuristicEnabled;
        ransacParams.distanceHeuristcLowerBound = params.distanceHeuristcLowerBound;
        ransacParams.distanceHeuristcUpperBound = params.distanceHeuristcUpperBound;
        ransacParams.itersNumEstimationHeuristicEnabled = params.itersNumEstimationHeuristicEnabled;
        ransacParams.itersNumHeuristicProbGoodEnoughModel = params.itersNumHeuristicProbGoodEnoughModel;
        ransacParams.itersNumHeuristicNotNoiseProb = params.itersNumHeuristicNotNoiseProb;
        return std::make_unique<RansacMatcher>(ransacFactory.make(ransacParams));
    }

    throw std::runtime_error("Invalid matcher method: " + params.matchingMethod);
}

} // namespace matcher
} // namespace improc
} // namespace model
