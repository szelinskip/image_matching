#pragma once

#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <helpers/Point.hpp>
#include "Transformation.hpp"

namespace model {
namespace improc {

using helpers::Point;
using PointsPair = std::pair<Point, Point>;

using Matrix8d = Eigen::Matrix<double, 8, 8>;
using Vector8d = Eigen::Matrix<double, 8, 1>;
using RowVector8d = Eigen::Matrix<double, 1, 8>;

class PerspectiveTransformation : public Transformation
{
public:
    PerspectiveTransformation(
        const PointsPair& pair1, const PointsPair& pair2, const PointsPair& pair3, const PointsPair& parir4);

    virtual Point applyTransformation(const Point& point) const override;

    virtual Eigen::Matrix2Xd applyMassiveTransformation(
        const Eigen::Matrix2Xd& points) const override;

private:
    Eigen::Matrix3d calculateModel(const PointsPair& pair1,
                                   const PointsPair& pair2,
                                   const PointsPair& pair3,
                                   const PointsPair& pair4) const;
};

} // namespace improc
} // namespace model
