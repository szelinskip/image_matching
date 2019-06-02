#pragma once

#include <cstdint>
#include <string>

namespace model {

struct ImageMatchingParams
{
    std::string matchingMethod;
    uint32_t neighborhoodSize;
    double neighborhoodConsistencyThreshold;
    double errorThreshold;
    uint32_t itersNum;
    bool distanceHeuristicEnabled;
    double distanceHeuristcLowerBound;
    double distanceHeuristcUpperBound;
    bool itersNumEstimationHeuristicEnabled;
    double itersNumHeuristicProbGoodEnoughModel;
    double itersNumHeuristicNotNoiseProb;
};

} // namespace model
