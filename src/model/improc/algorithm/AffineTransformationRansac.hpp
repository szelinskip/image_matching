#pragma once

#include <cstdint>

#include "RansacAlgo.hpp"
#include "Ransac.hpp"
#include <improc/algorithm/transformation/TransformationModelAffine.hpp>

namespace model {
namespace improc {
namespace algorithm {

class AffineTransformationRansac : public Ransac
{
public:
    AffineTransformationRansac(const double errorThreshold, const uint32_t itersNum);

    virtual std::pair<std::unique_ptr<TransformationModel>, MatrixData>
        runRansac(const MatchingPointsPairs& pointsPairs) override;

private:
    RansacAlgo<TransformationModelAffine> algo;
};

} // namespace algorithm
} // namespace improc
} // namespace model
