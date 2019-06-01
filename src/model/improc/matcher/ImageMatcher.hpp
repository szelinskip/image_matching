#pragma once

#include <Eigen/Dense>

#include <improc/ImageDescription.hpp>
#include <helpers/Point.hpp>

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using Points = std::vector<Point>;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class ImageMatcher
{
public:
    ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB);
    ~ImageMatcher();

    ImageMatcher() = delete;
    ImageMatcher(const ImageMatcher&) = delete;
    ImageMatcher& operator=(const ImageMatcher&) = delete;
    ImageMatcher(ImageMatcher&&) = delete;
    ImageMatcher& operator=(ImageMatcher&&) = delete;

    MatchingPointsPairs matchImages(const uint32_t neighborhoodSize,
                                    const double neighborhoodConsistencyThreshold) const;

private:
    Eigen::Matrix2Xd makePointsMatrix(const Points& points) const;

    const ImageDescription& imageA;
    const ImageDescription& imageB;
};

} // namespace matcher
} // namespace improc
} // namespace model
