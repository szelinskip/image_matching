#include "AffineTransformationRansac.hpp"

namespace model {
namespace improc {
namespace algorithm {

AffineTransformationRansac::AffineTransformationRansac(const double errorThreshold, const uint32_t itersNum)
    : Ransac()
    , algo(std::make_unique<RansacAlgo<ModelType>>(errorThreshold, itersNum, 3))
{
}

std::pair<std::unique_ptr<TransformationModel>, MatrixData>
    AffineTransformationRansac::runRansac(const MatchingPointsPairs& pointsPairs)
{
    return Ransac::run(*algo, pointsPairs);
}

uint32_t AffineTransformationRansac::getItersNum() const
{
    return algo->getItersNum();
}

std::unique_ptr<RansacAlgo<AffineTransformationRansac::ModelType>>& AffineTransformationRansac::getAlgoPtrRef()
{
    return algo;
}

} // namespace algorithm
} // namespace improc
} // namespace model
