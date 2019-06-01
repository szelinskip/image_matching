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

using Matrix6d = Eigen::Matrix<double, 6, 6>;
using Vector6d = Eigen::Matrix<double, 6, 1>;
using RowVector6d = Eigen::Matrix<double, 1, 6>;

class AffineTransformation : public Transformation
{
public:
    AffineTransformation(const PointsPair& pair1, const PointsPair& pair2, const PointsPair& pair3);

    virtual Point applyTransformation(const Point& point) const override;

    virtual Eigen::Matrix2Xd applyMassiveTransformation(
        const Eigen::Matrix2Xd& points) const override;

private:
    Eigen::Matrix3d calculateModel(const PointsPair& pair1,
                                   const PointsPair& pair2,
                                   const PointsPair& pair3) const;
};

} // namespace improc
} // namespace model
