#pragma once

#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <helpers/Point.hpp>


namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using PointsPair = std::pair<Point, Point>;

using Matrix6d = Eigen::Matrix<double, 6, 6>;
using Vector6d = Eigen::Matrix<double, 6, 1>;
using RowVector6d = Eigen::Matrix<double, 1, 6>;

class AffineTransformation
{
public:
    AffineTransformation();
    AffineTransformation(const PointsPair& pair1, const PointsPair& pair2, const PointsPair& pair3);
    ~AffineTransformation();

    AffineTransformation(const AffineTransformation&) = delete;
    AffineTransformation& operator=(const AffineTransformation&) = delete;
    AffineTransformation(AffineTransformation&&) = delete;
    AffineTransformation& operator=(AffineTransformation&&) = delete;
    Point applyTransformation(const Point& point) const;
    Eigen::Matrix2Xd applyMassiveTransformation(
        const Eigen::Matrix2Xd& points) const;

    void buildModel(const PointsPair& pair1,
                    const PointsPair& pair2,
                    const PointsPair& pair3);

private:
    Eigen::Matrix3d calculateModel(const PointsPair& pair1,
                                   const PointsPair& pair2,
                                   const PointsPair& pair3) const;

    Eigen::Matrix3d transformationMatrix;
};

} // namespace matcher
} // namespace improc
} // namespace model
