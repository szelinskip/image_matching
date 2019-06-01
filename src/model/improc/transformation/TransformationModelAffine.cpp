#include "TransformationModelAffine.hpp"

#include <memory>

#include "AffineTransformation.hpp"

namespace model {
namespace improc {

TransformationModelAffine::TransformationModelAffine(const std::vector<MatrixData::Sample>& samples)
    : TransformationModel(makeTransformation(samples))
{
}

std::unique_ptr<Transformation> TransformationModelAffine::makeTransformation(
    const std::vector<MatrixData::Sample>& samples)
{
    if(samples.size() != 3)
        throw std::runtime_error(
            "Affine transformation requires exactly 3 points. Provided: " + std::to_string(samples.size()));

    return std::make_unique<AffineTransformation>(samples[0], samples[1], samples[2]);
}

} // namespace improc
} // namespace model
