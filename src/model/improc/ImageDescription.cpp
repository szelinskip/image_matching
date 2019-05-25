#include "ImageDescription.hpp"

namespace model {
namespace improc {

ImageDescription::ImageDescription(std::vector<CharacteristicPoint>&& characteristicPoints,
                                   const std::string& imagePath)
    : characteristicPoints(std::move(characteristicPoints))
    , imagePath(imagePath)
{
}

ImageDescription::~ImageDescription() = default;

const std::vector<CharacteristicPoint> ImageDescription::getCharacteristicPoints() const
{
    return characteristicPoints;
}

void ImageDescription::setCharacteristicPoints(std::vector<CharacteristicPoint>&& characteristicPoints)
{
    this->characteristicPoints = std::move(characteristicPoints);
}

void ImageDescription::setImagePath(const std::string& imagePath)
{
    this->imagePath = imagePath;
}

const std::string ImageDescription::getImagePath() const
{
    return imagePath;
}

} // namespace improc
} // namespace model
