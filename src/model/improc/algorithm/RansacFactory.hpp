#pragma once

#include "Ransac.hpp"
#include "AffineTransformationRansac.hpp"
#include "PerspectiveTransformationRansac.hpp"
#include "RansacDistanceHeuristicDecorator.hpp"

namespace model {
namespace improc {
namespace algorithm {

struct RansacParams
{
    std::string ransacMethod;
    double errorThreshold;
    uint32_t itersNum;
    bool distanceHeuristicEnabled;
    double distanceHeuristcLowerBound;
    double distanceHeuristcUpperBound;
    bool itersNumEstimationHeuristicEnabled;
    double itersNumHeuristicProbGoodEnoughModel;
    double itersNumHeuristicNotNoiseProb;
};

class RansacFactory
{
public:
    std::unique_ptr<Ransac> make(const RansacParams& params);

private:
    template<class AlgoType>
    std::unique_ptr<Ransac> makeAlgo(const RansacParams& params);
};

template<class AlgoType>
std::unique_ptr<Ransac> RansacFactory::makeAlgo(const RansacParams& params)
{
    std::unique_ptr<Ransac> ransac = std::make_unique<AlgoType>(params.errorThreshold, params.itersNum);

    if(params.distanceHeuristicEnabled)
    {
        AlgoType* ransacDerived = static_cast<AlgoType*>(ransac.get());
        std::unique_ptr<RansacAlgo<typename AlgoType::ModelType>>& algo = ransacDerived->getAlgoPtrRef();
        Ransac::decorate<typename AlgoType::ModelType,
                         RansacDistanceHeuristicDecorator>(
            algo, params.distanceHeuristcLowerBound, params.distanceHeuristcUpperBound);
    }

    return ransac;
}

} // namespace algorithm
} // namespace improc
} // namespace model
