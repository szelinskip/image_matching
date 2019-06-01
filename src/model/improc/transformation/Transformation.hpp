#pragma once

#include <vector>

#include <Eigen/Dense>

#include <helpers/Point.hpp>
#include "MatrixData.hpp"

namespace model {
namespace improc {

class Transformation
{
public:
    Transformation(Eigen::Matrix3d&& transformationMatrix);
    virtual ~Transformation();

    Transformation() = delete;
    Transformation(const Transformation&) = delete;
    Transformation& operator=(const Transformation&) = delete;
    Transformation(Transformation&&) = delete;
    Transformation& operator=(Transformation&&) = delete;

    virtual helpers::Point applyTransformation(const helpers::Point& point) const = 0;
    virtual Eigen::Matrix2Xd applyMassiveTransformation(const Eigen::Matrix2Xd& points) const = 0;

protected:
    Eigen::Matrix3d transformationMatrix;
};

} // namespace improc
} // namespace model
