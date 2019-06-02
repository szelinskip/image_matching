#pragma once

#include <memory>

#include <Eigen/Dense>

#include <improc/ImageDescription.hpp>
#include <helpers/Point.hpp>
#include "Matcher.hpp"

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
using Points = std::vector<Point>;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class ImageMatcher
{
public:
    ImageMatcher(const ImageDescription& imageA, const ImageDescription& imageB,
                 std::unique_ptr<Matcher>&& matcher);
    ~ImageMatcher();

    ImageMatcher() = delete;
    ImageMatcher(const ImageMatcher&) = delete;
    ImageMatcher& operator=(const ImageMatcher&) = delete;
    ImageMatcher(ImageMatcher&&) = delete;
    ImageMatcher& operator=(ImageMatcher&&) = delete;

    MatchingPointsPairs matchImages() const;

private:
    const ImageDescription& imageA;
    const ImageDescription& imageB;

    std::unique_ptr<Matcher> matcher;
};

} // namespace matcher
} // namespace improc
} // namespace model
