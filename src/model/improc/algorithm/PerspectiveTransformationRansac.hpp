#pragma once

#include <cstdint>

#include "RansacAlgo.hpp"
#include "Ransac.hpp"
#include <improc/algorithm/transformation/TransformationModelPerspective.hpp>

namespace model {
namespace improc {
namespace algorithm {

class PerspectiveTransformationRansac : public Ransac
{
public:
    PerspectiveTransformationRansac(const double errorThreshold, const uint32_t itersNum);

    virtual std::pair<std::unique_ptr<TransformationModel>, MatrixData>
        runRansac(const MatchingPointsPairs& pointsPairs) override;

private:
    RansacAlgo<TransformationModelPerspective> algo;
};

} // namespace algorithm
} // namespace improc
} // namespace model
