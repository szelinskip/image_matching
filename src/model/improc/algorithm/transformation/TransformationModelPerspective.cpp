#include "TransformationModelPerspective.hpp"

#include <memory>

#include "PerspectiveTransformation.hpp"

namespace model {
namespace improc {

TransformationModelPerspective::TransformationModelPerspective(const std::vector<MatrixData::Sample>& samples)
    : TransformationModel(makeTransformation(samples))
{
}

std::unique_ptr<Transformation> TransformationModelPerspective::makeTransformation(
    const std::vector<MatrixData::Sample>& samples)
{
    if(samples.size() != 4)
        throw std::runtime_error(
            "Affine transformation requires exactly 4 points. Provided: " + std::to_string(samples.size()));

    return std::make_unique<PerspectiveTransformation>(samples[0], samples[1], samples[2], samples[3]);
}

} // namespace improc
} // namespace model
