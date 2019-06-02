#pragma once

#include <memory>
#include <vector>

#include <Eigen/Dense>

#include "MatrixData.hpp"
#include "Transformation.hpp"

namespace model {
namespace improc {

class TransformationModel
{
public:
    typedef MatrixData Data;

    TransformationModel(std::unique_ptr<Transformation>&& transformation);
    virtual ~TransformationModel();

    TransformationModel(const TransformationModel&) = delete;
    TransformationModel& operator=(const TransformationModel&) = delete;
    TransformationModel(TransformationModel&&) = delete;
    TransformationModel& operator=(TransformationModel&&) = delete;

    std::vector<double> getErrorVec(const Data& data) const;

    const Transformation& getTransformation() const;

protected:
    std::unique_ptr<Transformation> transformation;

private:
    Eigen::Matrix2Xd getFirstPoints(const Data& data) const;
    Eigen::Matrix2Xd getSecondPoints(const Data& data) const;
};

} // namespace improc
} // namespace model
