#pragma once

#include <cstdint>
#include <memory>

#include "RansacAlgo.hpp"
#include "Ransac.hpp"
#include <improc/algorithm/transformation/TransformationModelAffine.hpp>

namespace model {
namespace improc {
namespace algorithm {

class AffineTransformationRansac : public Ransac
{
public:
    typedef TransformationModelAffine ModelType;

    AffineTransformationRansac(const double errorThreshold, const uint32_t itersNum);

    virtual std::pair<std::unique_ptr<TransformationModel>, MatrixData>
        runRansac(const MatchingPointsPairs& pointsPairs) override;

    virtual uint32_t getItersNum() const override;

    std::unique_ptr<RansacAlgo<ModelType>>& getAlgoPtrRef();

private:
    std::unique_ptr<RansacAlgo<ModelType>> algo;
};

} // namespace algorithm
} // namespace improc
} // namespace model
