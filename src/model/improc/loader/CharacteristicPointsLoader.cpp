#include "CharacteristicPointsLoader.hpp"

#include <cstdint>
#include <fstream>
#include <iterator>
#include <sstream>

namespace model {
namespace improc {
namespace loader {

const std::vector<CharacteristicPoint>& CharacteristicPointsLoader::loadCharacterisitcPoints(
    const std::string& pathToFeatures)
{
    std::ifstream featuresFileStream(pathToFeatures);
    if (!featuresFileStream.is_open())
        throw std::runtime_error("Could not read file: " + pathToFeatures);

    std::string line;
    uint32_t lineNum = 0u;
    characterisitcPoints.clear();
    while (std::getline(featuresFileStream, line))
    {
        lineNum++;
        decideWhatToDoWithLine(line, lineNum);
    }
    return characterisitcPoints;
}

void CharacteristicPointsLoader::decideWhatToDoWithLine(const std::string& line, const uint32_t lineNum)
{
    if(lineNum == 1u)
    {
        featuresNum = std::stoi(line);
    }
    else if(lineNum == 2u)
    {
        pointsNum = std::stoi(line);
        characterisitcPoints.reserve(static_cast<size_t>(pointsNum));
    }
    else  // lineNum > 2u
    {
        readCharacteristicPoint(line);
    }
}

void CharacteristicPointsLoader::readCharacteristicPoint(const std::string& line)
{
    std::istringstream lineStream(line);
    auto beginIt = std::istream_iterator<std::string>(lineStream);
    auto endIt = std::istream_iterator<std::string>();
    CharacteristicPoint characteristicPoint;
    Point point;
    std::vector<int32_t> features;
    features.reserve(static_cast<size_t>(featuresNum));
    uint32_t i = 0u;
    for(auto it = beginIt; it != endIt; it++)
    {
        const auto& token = *it;
        if(i == 0u)
        {
            point.X() = std::stod(token);
        }
        else if(i == 1u)
        {
            point.Y() = std::stod(token);
            characteristicPoint.setPoint(point);
        }
        else if(i >= 5)
        {
            features.push_back(std::stoi(token));
        }
        i++;
    }
    characteristicPoint.setFeatures(std::move(features));
    characterisitcPoints.push_back(std::move(characteristicPoint));
}

} // namespace loader
} // namespace improc
} // namespace model
