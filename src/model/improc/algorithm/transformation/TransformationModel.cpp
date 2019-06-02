#include "TransformationModel.hpp"

namespace model {
namespace improc {

TransformationModel::TransformationModel(std::unique_ptr<Transformation>&& transformation)
    : transformation(std::move(transformation))
{
}

TransformationModel::~TransformationModel() = default;

std::vector<double> TransformationModel::getErrorVec(const Data& data) const
{
    Eigen::Matrix2Xd firstPoints = getFirstPoints(data);
    Eigen::Matrix2Xd transformedPoints = transformation->applyMassiveTransformation(firstPoints);
    Eigen::Matrix2Xd secondPoints = getSecondPoints(data);

    Eigen::VectorXd errorVec =
        (transformedPoints - secondPoints)
            .array().square().colwise().sum().array().sqrt();

    return std::vector<double>(errorVec.data(), errorVec.data() + errorVec.size());
}

const Transformation& TransformationModel::getTransformation() const
{
    return *transformation;
}

Eigen::Matrix2Xd TransformationModel::getFirstPoints(const Data& data) const
{
    const Eigen::Matrix4Xd& dataMatrix = data.getData();
    return dataMatrix.block(0, 0, 2, dataMatrix.cols());
}

Eigen::Matrix2Xd TransformationModel::getSecondPoints(const TransformationModel::Data &data) const
{
    const Eigen::Matrix4Xd& dataMatrix = data.getData();
    return dataMatrix.block(2, 0, 2, dataMatrix.cols());
}

} // namespace improc
} // namespace model
