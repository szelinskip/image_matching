#pragma once

#include <string>

namespace controller {

struct RawImageMatchingParams
{
    std::string selectedMatcherMethod;
    std::string neighborhoodSizeStr;
    std::string neighborhoodConsistencyThresholdStr;
    std::string errorThresholdStr;
    std::string itersNumStr;
    bool distanceHeuristicSelected;
    std::string distanceHeuristcLowerBoundStr;
    std::string distanceHeuristcUpperBoundStr;
    bool itersNumEstimationHeuristicSelected;
    std::string itersNumHeuristicProbGoodEnoughModelStr;
    std::string itersNumHeuristicNotNoiseProbStr;
};

} // namespace controller
