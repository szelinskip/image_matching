#pragma once

#include <string>
#include <vector>

#include "CharacteristicPoint.hpp"

namespace model {
namespace improc {

class ImageDescription
{
public:
    ImageDescription(std::vector<CharacteristicPoint>&& characteristicPoints, const std::string& imagePath);
    ~ImageDescription();

    ImageDescription() = delete;
    ImageDescription(const ImageDescription&) = delete;
    ImageDescription& operator=(const ImageDescription&) = delete;
    ImageDescription(ImageDescription&&) = delete;
    ImageDescription& operator=(ImageDescription&&) = delete;

    const std::vector<CharacteristicPoint> getCharacteristicPoints() const;
    void setCharacteristicPoints(std::vector<CharacteristicPoint>&& characteristicPoints);
    void setImagePath(const std::string& imagePath);
    const std::string getImagePath() const;

private:
    std::vector<CharacteristicPoint> characteristicPoints;
    std::string imagePath;
};

} // namespace improc
} // namespace model
