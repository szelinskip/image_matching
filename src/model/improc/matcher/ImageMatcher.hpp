#pragma once

#include <memory>

#include <Eigen/Dense>

#include <improc/ImageDescription.hpp>
#include <helpers/Point.hpp>
#include "Matcher.hpp"
#include "MatchingResult.hpp"

namespace model {
namespace improc {
namespace matcher {

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

    MatchingResult matchImages() const;

private:
    const ImageDescription& imageA;
    const ImageDescription& imageB;

    std::unique_ptr<Matcher> matcher;
};

} // namespace matcher
} // namespace improc
} // namespace model
