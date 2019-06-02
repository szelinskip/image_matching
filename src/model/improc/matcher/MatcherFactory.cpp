#include "MatcherFactory.hpp"

#include "NeighborhoodConsistencyMatcher.hpp"
#include "RansacMatcher.hpp"
#include <improc/algorithm/NeighborhoodConsistency.hpp>
#include <improc/algorithm/AffineTransformationRansac.hpp>
#include <improc/algorithm/PerspectiveTransformationRansac.hpp>

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

    if(params.matchingMethod == "RANSAC Affine")
    {
        return std::make_unique<RansacMatcher>(
            std::make_unique<algorithm::AffineTransformationRansac>(
                params.errorThreshold, params.itersNum));
    }

    if(params.matchingMethod == "RANSAC Perspective")
    {
        return std::make_unique<RansacMatcher>(
            std::make_unique<algorithm::PerspectiveTransformationRansac>(
                params.errorThreshold, params.itersNum));
    }

    throw std::runtime_error("Invalid matcher method: " + params.matchingMethod);
}

} // namespace matcher
} // namespace improc
} // namespace model
