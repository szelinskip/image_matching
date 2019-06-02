#include "AffineTransformationRansac.hpp"

namespace model {
namespace improc {
namespace algorithm {

AffineTransformationRansac::AffineTransformationRansac(const double errorThreshold, const uint32_t itersNum)
    : Ransac()
    , algo(errorThreshold, itersNum, 3)
{
}

std::pair<std::unique_ptr<TransformationModel>, MatrixData>
    AffineTransformationRansac::runRansac(const MatchingPointsPairs& pointsPairs)
{
    return Ransac::run(algo, pointsPairs);
}

} // namespace algorithm
} // namespace improc
} // namespace model
