#pragma once

#include <memory>
#include <string>

#include <improc/ImageDescription.hpp>

namespace model {

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class ImageMatchingService
{
public:

    MatchingPointsPairs matchImages();

    void setImageAPath(const std::string& imageAPath);
    void setImageBPath(const std::string& imageBPath);

private:
    void initImages();

    std::string imageAPath;
    std::string imageBPath;

    std::unique_ptr<improc::ImageDescription> imageA;
    std::unique_ptr<improc::ImageDescription> imageB;
};

} // namespace model
