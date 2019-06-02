#pragma once

#include <cstdint>
#include <chrono>
#include <vector>

#include <helpers/Point.hpp>

namespace model {
namespace improc {
namespace matcher {

using MatchingPointsPairs = std::vector<std::pair<helpers::Point, helpers::Point>>;

struct MatchingResult
{
    MatchingPointsPairs finalMatchingPairs;
    uint32_t imageACharacteristicsPointsNum;
    uint32_t imageBCharacteristicsPointsNum;
    uint32_t mutualNeighborhoodPointsPairs;
    uint32_t finalNumOfMatchingPointsPairs;
    uint32_t ransacItersNum;
    std::chrono::milliseconds elapsedTime;
};

} // namespace matcher
} // namespace improc
} // namespace model
