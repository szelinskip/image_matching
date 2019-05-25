#pragma once

#include <string>
#include <vector>

#include <improc/CharacteristicPoint.hpp>

namespace model {
namespace improc {
namespace loader {

class CharacteristicPointsLoader
{
public:
    const std::vector<CharacteristicPoint>& loadCharacterisitcPoints(const std::string& pathToFeatures);

private:
    void decideWhatToDoWithLine(const std::string& line, const uint32_t lineNum);
    void readCharacteristicPoint(const std::string& line);

    std::vector<CharacteristicPoint> characterisitcPoints;
    int32_t featuresNum;
    int32_t pointsNum;
};

} // namespace loader
} // namespace improc
} // namespace model
