#include "AffineTransformation.hpp"

namespace model {
namespace improc {
namespace matcher {

AffineTransformation::AffineTransformation() = default;

AffineTransformation::AffineTransformation(const PointsPair& pair1,
                                           const PointsPair& pair2,
                                           const PointsPair& pair3)
    :transformationMatrix(calculateModel(pair1, pair2, pair3))
{
}

AffineTransformation::~AffineTransformation() = default;

Point AffineTransformation::applyTransformation(const Point& point) const
{
    Eigen::Vector3d pointVec(point.getX(), point.getY(), 1);
    Eigen::Vector3d transformationResultVec = transformationMatrix * pointVec;
    return Point{transformationResultVec(0), transformationResultVec(1)};
}

Eigen::Matrix2Xd AffineTransformation::applyMassiveTransformation(
    const Eigen::Matrix2Xd& points) const
{
    Eigen::MatrixXd pointsLocal = points;
    pointsLocal.conservativeResize(pointsLocal.rows() + 1, Eigen::NoChange);
    Eigen::VectorXd vectorOfOnes = Eigen::VectorXd::Ones(pointsLocal.cols());
    pointsLocal.row(pointsLocal.rows() - 1) = vectorOfOnes;

    Eigen::MatrixXd pointsTransformed = transformationMatrix * pointsLocal;
    pointsTransformed.conservativeResize(pointsTransformed.rows() - 1, Eigen::NoChange);  // remove last row

    return pointsTransformed;
}

void AffineTransformation::buildModel(const PointsPair& pair1,
                                      const PointsPair& pair2,
                                      const PointsPair& pair3)
{
    transformationMatrix = calculateModel(pair1, pair2, pair3);
}

Eigen::Matrix3d AffineTransformation::calculateModel(const PointsPair& pair1,
                                          const PointsPair& pair2,
                                          const PointsPair& pair3) const
{
    Matrix6d xMatrix;
    xMatrix << pair1.first.getX() , pair1.first.getY() , 1 , 0 , 0 , 0,
               pair2.first.getX() , pair2.first.getY() , 1 , 0 , 0 , 0,
               pair3.first.getX() , pair3.first.getY() , 1 , 0 , 0 , 0,
               0 , 0 , 0 , pair1.first.getX() , pair1.first.getY() , 1,
               0 , 0 , 0 , pair2.first.getX() , pair2.first.getY() , 1,
               0 , 0 , 0 , pair3.first.getX() , pair3.first.getY() , 1;

    Vector6d xPrimeVec;
    xPrimeVec << pair1.second.getX(),
                 pair2.second.getX(),
                 pair3.second.getX(),
                 pair1.second.getY(),
                 pair2.second.getY(),
                 pair3.second.getY();

    Vector6d transformationVector = xMatrix.inverse() * xPrimeVec;
    RowVector6d transformationVectorT = transformationVector.transpose();
    Eigen::Matrix3d transformationMatrix;
    transformationMatrix << transformationVectorT.segment<3>(0),
                            transformationVectorT.segment<3>(3),
                            0, 0, 1;
    return transformationMatrix;
}

} // namespace matcher
} // namespace improc
} // namespace model
