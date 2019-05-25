#include "ImageMatchingService.hpp"

#include <improc/HarrisSiftExtractor.hpp>
#include <improc/loader/CharacteristicPointsLoader.hpp>
#include <improc/matcher/ImageMatcher.hpp>

namespace model {

MatchingPointsPairs ImageMatchingService::matchImages()
{
    initImages();

    improc::matcher::ImageMatcher matcher(*imageA, *imageB);
    return matcher.matchImages();
}

void ImageMatchingService::initImages()
{
    improc::HarrisSiftExtractor extractor;
    std::string characteristicPointsImageAPath =
        extractor.extractImageFeatures(imageAPath);

    improc::loader::CharacteristicPointsLoader loader;
    std::vector<improc::CharacteristicPoint> characteristicPointsImageA =
        loader.loadCharacterisitcPoints(characteristicPointsImageAPath);

    imageA = std::make_unique<improc::ImageDescription>(std::move(characteristicPointsImageA), imageAPath);

    std::string characteristicPointsImageBPath =
        extractor.extractImageFeatures(imageBPath);

    std::vector<improc::CharacteristicPoint> characteristicPointsImageB =
        loader.loadCharacterisitcPoints(characteristicPointsImageBPath);

    imageB = std::make_unique<improc::ImageDescription>(std::move(characteristicPointsImageB), imageBPath);
}

void ImageMatchingService::setImageAPath(const std::string& imageAPath)
{
    this->imageAPath = imageAPath;
}

void ImageMatchingService::setImageBPath(const std::string& imageBPath)
{
    this->imageBPath = imageBPath;
}

} // namespace model
