#include "PerspectiveTransformationRansac.hpp"

namespace model {
namespace improc {
namespace algorithm {

PerspectiveTransformationRansac::PerspectiveTransformationRansac(
    const double errorThreshold, const uint32_t itersNum)
    : Ransac()
    , algo(std::make_unique<RansacAlgo<ModelType>>(errorThreshold, itersNum, 4))
{
}

std::pair<std::unique_ptr<TransformationModel>, MatrixData>
    PerspectiveTransformationRansac::runRansac(const MatchingPointsPairs& pointsPairs)
{
    return Ransac::run(*algo, pointsPairs);
}

std::unique_ptr<RansacAlgo<PerspectiveTransformationRansac::ModelType>>&
    PerspectiveTransformationRansac::getAlgoPtrRef()
{
    return algo;
}

} // namespace algorithm
} // namespace improc
} // namespace model
