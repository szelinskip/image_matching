#pragma once

#include <memory>
#include <string>

#include <improc/ImageDescription.hpp>

namespace controller {
class MainController;
} // namespace controller

namespace model {

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class ImageMatchingService
{
public:
    void setController(controller::MainController* controller);

    MatchingPointsPairs matchImages();

    void setImageAPath(const std::string& imageAPath);
    const std::string getImageAPath() const;
    void setImageBPath(const std::string& imageBPath);
    const std::string getImageBPath() const;

private:
    void initImages();

    controller::MainController* controller;

    std::string imageAPath;
    std::string imageBPath;

    std::unique_ptr<improc::ImageDescription> imageA;
    std::unique_ptr<improc::ImageDescription> imageB;
};

} // namespace model
