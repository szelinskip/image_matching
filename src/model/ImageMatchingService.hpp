#pragma once

#include <memory>
#include <string>

#include <improc/ImageDescription.hpp>
#include "ImageMatchingParams.hpp"
#include <improc/matcher/MatcherFactory.hpp>
#include <improc/matcher/MatchingResult.hpp>

namespace controller {
class MainController;
} // namespace controller

namespace model {

class ImageMatchingService
{
public:
    void setController(controller::MainController* controller);

    improc::matcher::MatchingResult matchImages(const ImageMatchingParams& params);

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

    improc::matcher::MatcherFactory matcherFactory;
};

} // namespace model
