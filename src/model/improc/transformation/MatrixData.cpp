#include "MatrixData.hpp"

namespace model {
namespace improc {

MatrixData::MatrixData() = default;

MatrixData::MatrixData(Eigen::Matrix4Xd&& matrix)
    : data(std::move(matrix))
{
}

MatrixData::MatrixData(const std::vector<MatrixData::Sample>& pointsPairs)
    : data(makePointsPairsMatrix(pointsPairs))
{
}

MatrixData::~MatrixData() = default;
MatrixData::MatrixData(const MatrixData&) = default;
MatrixData& MatrixData::operator=(const MatrixData &) = default;
MatrixData::MatrixData(MatrixData&&) = default;
MatrixData& MatrixData::operator=(MatrixData&&) = default;

const Eigen::Matrix4Xd& MatrixData::getData() const
{
    return data;
}

uint32_t MatrixData::size() const
{
    return static_cast<uint32_t> (data.cols());
}

MatrixData::Sample MatrixData::getSample(const uint32_t index) const
{
    return Sample{helpers::Point{data(0, index), data(1, index)},
        helpers::Point{data(2, index), data(3, index)}};
}

void MatrixData::addSample(const MatrixData::Sample& sample)
{
    Eigen::Vector4d sampleVec(
        sample.first.getX(), sample.first.getY(),
        sample.second.getX(), sample.second.getY());

    data.conservativeResize(Eigen::NoChange, data.cols() + 1);
    data.col(data.cols() - 1) = sampleVec;
}

std::vector<MatrixData::Sample> MatrixData::getDataAsPointsPairsVec()
{
    std::vector<MatrixData::Sample> pointsPairsVec;
    pointsPairsVec.reserve(static_cast<uint32_t>(data.cols()));
    for(auto i = 0u; i < data.cols(); i++)
    {
        pointsPairsVec.push_back(MatrixData::Sample{helpers::Point{data.col(i)(0), data.col(i)(1)},
                                                    helpers::Point{data.col(i)(2), data.col(i)(3)}});
    }

    return pointsPairsVec;
}

Eigen::Matrix4Xd MatrixData::makePointsPairsMatrix(const std::vector<Sample>& pointsPairs) const
{
    Eigen::Matrix4Xd pointsMatrix;
    for(const auto& pointsPair : pointsPairs)
    {
        Eigen::Vector4d pointVec(pointsPair.first.getX(), pointsPair.first.getY(),
                                 pointsPair.second.getX(), pointsPair.second.getY());
        pointsMatrix.conservativeResize(Eigen::NoChange, pointsMatrix.cols() + 1);
        pointsMatrix.col(pointsMatrix.cols() - 1) = std::move(pointVec);
    }

    return pointsMatrix;
}

} // namespace improc
} // namespace model
