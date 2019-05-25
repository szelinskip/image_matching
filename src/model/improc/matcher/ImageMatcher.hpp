#pragma once

#include <improc/ImageDescription.hpp>
#include <helpers/Point.hpp>

namespace model {
namespace improc {
namespace matcher {

using helpers::Point;
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

    MatchingPointsPairs matchImages() const;

private:
    const ImageDescription& imageA;
    const ImageDescription& imageB;
};

} // namespace matcher
} // namespace improc
} // namespace model
