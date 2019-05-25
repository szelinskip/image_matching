#include "MutualNearestNeighbor.hpp"

#include <limits>

#include <cstdint>

#include <utils/MathUtils.hpp>

namespace model {
namespace improc {
namespace matcher {

MatchingPointsPairs MutualNearestNeighbor::matchImages(const ImageDescription& imageA,
                                                      const ImageDescription& imageB) const
{
    // TODO: use library for linear algebra

    // assumption imageA.characteristicPoints.size() == imageB.characteristicPoints.size() ????

    std::vector<uint32_t> nearestNeighboursForA(imageA.getCharacteristicPoints().size());

    const auto& characteristicPointsA = imageA.getCharacteristicPoints();
    const auto& characteristicPointsB = imageB.getCharacteristicPoints();

    for(auto i = 0u; i < characteristicPointsA.size(); i++)
    {
        double minDistance = std::numeric_limits<double>::infinity();
        uint32_t indexOfMatchingPoint = 0;
        for(auto j = 0u; j < characteristicPointsB.size(); j++)
        {
            double distance = utils::euclideanDistance(
                characteristicPointsA[i].getFeatures(),
                characteristicPointsB[j].getFeatures());

            if(distance < minDistance)
            {
                minDistance = distance;
                indexOfMatchingPoint = j;
            }
        }
        nearestNeighboursForA[i] = indexOfMatchingPoint;
    }

    std::vector<uint32_t> nearestNeighboursForB(imageB.getCharacteristicPoints().size());

    for(auto i = 0u; i < characteristicPointsB.size(); i++)
    {
        double minDistance = std::numeric_limits<double>::infinity();
        uint32_t indexOfMatchingPoint = 0;
        for(auto j = 0u; j < characteristicPointsA.size(); j++)
        {
            double distance = utils::euclideanDistance(
                characteristicPointsB[i].getFeatures(),
                characteristicPointsA[j].getFeatures());

            if(distance < minDistance)
            {
                minDistance = distance;
                indexOfMatchingPoint = j;
            }
        }
        nearestNeighboursForB[i] = indexOfMatchingPoint;
    }

    MatchingPointsPairs matchingPointsPairs;

    for(auto i = 0u; i < characteristicPointsB.size(); i++)
    {
        if(nearestNeighboursForB[i] == nearestNeighboursForA[nearestNeighboursForB[i]])
        {
            matchingPointsPairs.emplace_back(characteristicPointsB[i].getPoint(),
                                             characteristicPointsA[nearestNeighboursForB[i]].getPoint());
        }
    }

    return matchingPointsPairs;
}

} // namespace matcher
} // namespace improc
} // namespace model
