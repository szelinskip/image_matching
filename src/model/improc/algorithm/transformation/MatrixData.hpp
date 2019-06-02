#pragma once

#include <utility>

#include <Eigen/Dense>

#include <helpers/Point.hpp>

namespace model {
namespace improc {

class MatrixData
{
public:
    typedef std::pair<helpers::Point, helpers::Point> Sample;

    MatrixData();
    explicit MatrixData(Eigen::Matrix4Xd&& matrix);
    explicit MatrixData(const std::vector<Sample>& pointsPairs);
    ~MatrixData();

    MatrixData(const MatrixData&);
    MatrixData& operator=(const MatrixData&);
    MatrixData(MatrixData&&);
    MatrixData& operator=(MatrixData&&);

    const Eigen::Matrix4Xd& getData() const;
    uint32_t size() const;
    Sample getSample(const uint32_t index) const;
    void addSample(const Sample& sample);
    std::vector<Sample> getDataAsPointsPairsVec();

private:
    Eigen::Matrix4Xd makePointsPairsMatrix(const std::vector<Sample>& pointsPairs) const;

    Eigen::Matrix4Xd data;
};

} // namespace improc
} // namespace model
