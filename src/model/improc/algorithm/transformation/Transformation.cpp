#include "Transformation.hpp"

namespace model {
namespace improc {

Transformation::Transformation(Eigen::Matrix3d&& transformationMatrix)
    : transformationMatrix(std::move(transformationMatrix))
{
}

Transformation::~Transformation() = default;

} // namespace improc
} // namespace model
