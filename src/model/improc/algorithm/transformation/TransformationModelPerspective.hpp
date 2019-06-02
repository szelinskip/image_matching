#pragma once

#include <vector>

#include "MatrixData.hpp"
#include "TransformationModel.hpp"
#include "Transformation.hpp"

namespace model {
namespace improc {

class TransformationModelPerspective : public TransformationModel
{
public:
    TransformationModelPerspective(const std::vector<MatrixData::Sample>& samples);

private:
    std::unique_ptr<Transformation> makeTransformation(const std::vector<MatrixData::Sample>& samples);
};

} // namespace improc
} // namespace model
