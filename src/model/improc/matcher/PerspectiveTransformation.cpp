#include "PerspectiveTransformation.hpp"

namespace model {
namespace improc {
namespace matcher {

PerspectiveTransformation::PerspectiveTransformation() = default;

PerspectiveTransformation::PerspectiveTransformation(const PointsPair& pair1,
                                                     const PointsPair& pair2,
                                                     const PointsPair& pair3,
                                                     const PointsPair& pair4)
    :transformationMatrix(calculateModel(pair1, pair2, pair3, pair4))
{
}

PerspectiveTransformation::~PerspectiveTransformation() = default;

Point PerspectiveTransformation::applyTransformation(const Point& point) const
{
    Eigen::Vector3d pointVec(point.getX(), point.getY(), 1);
    Eigen::Vector3d transformationResultVec = transformationMatrix * pointVec;
    return Point{transformationResultVec(0) / transformationResultVec(2),
                 transformationResultVec(1) / transformationResultVec(2)};
}

Eigen::Matrix2Xd PerspectiveTransformation::applyMassiveTransformation(
    const Eigen::Matrix2Xd& points) const
{
    Eigen::MatrixXd pointsLocal = points;
    pointsLocal.conservativeResize(pointsLocal.rows() + 1, Eigen::NoChange);
    Eigen::VectorXd vectorOfOnes = Eigen::VectorXd::Ones(pointsLocal.cols());
    pointsLocal.row(pointsLocal.rows() - 1) = vectorOfOnes;

    Eigen::MatrixXd pointsTransformed = transformationMatrix * pointsLocal;

    Eigen::Matrix2Xd normalizedTransformedPoints = pointsTransformed.colwise().hnormalized();

    return normalizedTransformedPoints;
}

void PerspectiveTransformation::buildModel(const PointsPair& pair1,
                                           const PointsPair& pair2,
                                           const PointsPair& pair3,
                                           const PointsPair& pair4)
{
    transformationMatrix = calculateModel(pair1, pair2, pair3, pair4);
}

Eigen::Matrix3d PerspectiveTransformation::calculateModel(const PointsPair& pair1,
                                                          const PointsPair& pair2,
                                                          const PointsPair& pair3,
                                                          const PointsPair& pair4) const
{
    Matrix8d xMatrix;
    xMatrix <<
        pair1.first.getX(), pair1.first.getY(), 1, 0, 0, 0,
                -pair1.second.getX() * pair1.first.getX(), -pair1.second.getX() * pair1.first.getY(),
        pair2.first.getX() , pair2.first.getY(), 1, 0, 0, 0,
                -pair2.second.getX() * pair2.first.getX(), -pair2.second.getX() * pair2.first.getY(),
        pair3.first.getX() , pair3.first.getY(), 1, 0, 0, 0,
                -pair3.second.getX() * pair3.first.getX(), -pair3.second.getX() * pair3.first.getY(),
        pair4.first.getX() , pair4.first.getY(), 1, 0, 0, 0,
                -pair4.second.getX() * pair4.first.getX(), -pair4.second.getX() * pair4.first.getY(),
        0, 0, 0, pair1.first.getX(), pair1.first.getY(), 1,
                -pair1.second.getY() * pair1.first.getX(), -pair1.second.getY() * pair1.first.getY(),
        0, 0, 0, pair2.first.getX(), pair2.first.getY(), 1,
                -pair2.second.getY() * pair2.first.getX(), -pair2.second.getY() * pair2.first.getY(),
        0, 0, 0, pair3.first.getX(), pair3.first.getY(), 1,
                -pair3.second.getY() * pair3.first.getX(), -pair3.second.getY() * pair3.first.getY(),
        0, 0, 0, pair4.first.getX(), pair4.first.getY(), 1,
                -pair4.second.getY() * pair4.first.getX(), -pair4.second.getY() * pair4.first.getY();

    Vector8d xPrimeVec;
    xPrimeVec << pair1.second.getX(),
                 pair2.second.getX(),
                 pair3.second.getX(),
                 pair4.second.getX(),
                 pair1.second.getY(),
                 pair2.second.getY(),
                 pair3.second.getY(),
                 pair4.second.getY();

    Vector8d transformationVector = xMatrix.inverse() * xPrimeVec;
    RowVector8d transformationVectorT = transformationVector.transpose();
    Eigen::Matrix3d transformationMatrix;
    transformationMatrix << transformationVectorT.segment<3>(0),
                            transformationVectorT.segment<3>(3),
                            transformationVectorT.segment<2>(6), 1;
    return transformationMatrix;
}

} // namespace matcher
} // namespace improc
} // namespace model
