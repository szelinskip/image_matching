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
    typedef TransformationModelPerspective ModelType;

    PerspectiveTransformationRansac(const double errorThreshold, const uint32_t itersNum);

    virtual std::pair<std::unique_ptr<TransformationModel>, MatrixData>
        runRansac(const MatchingPointsPairs& pointsPairs) override;

    std::unique_ptr<RansacAlgo<ModelType>>& getAlgoPtrRef();

private:
    std::unique_ptr<RansacAlgo<ModelType>> algo;
};

} // namespace algorithm
} // namespace improc
} // namespace model
