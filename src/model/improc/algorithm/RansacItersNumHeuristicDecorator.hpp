#pragma once

#include <cmath>
#include <cstdint>
#include <memory>
#include <utility>

#include "RansacAlgo.hpp"

namespace model {
namespace improc {
namespace algorithm {

template<class Model, class Data = typename Model::Data, class Sample = typename Data::Sample>
class RansacItersNumHeuristicDecorator : public RansacAlgo<Model, Data, Sample>
{
public:
    using RansacAlgoPtr = std::unique_ptr<RansacAlgo<Model, Data, Sample>>;

    RansacItersNumHeuristicDecorator(RansacAlgoPtr&& algo,
                                     double itersNumHeuristicProbGoodEnoughModel,
                                     double itersNumHeuristicNotNoiseProb);

    virtual std::pair<std::unique_ptr<Model>, Data> runRansac(const Data& data) override;
    virtual std::vector<Sample> getSamplesRandomly(const Data& data) override;

private:
    uint32_t calculateItersNumEstimation() const;

    RansacAlgoPtr baseAlgo;
    double itersNumHeuristicProbGoodEnoughModel;
    double itersNumHeuristicNotNoiseProb;
};

template<class Model, class Data, class Sample>
RansacItersNumHeuristicDecorator<Model, Data, Sample>
    ::RansacItersNumHeuristicDecorator(RansacAlgoPtr&& algo,
                                       double itersNumHeuristicProbGoodEnoughModel,
                                       double itersNumHeuristicNotNoiseProb)
    : RansacAlgo<Model, Data, Sample>(algo->getErrorThreshold(), algo->getItersNum(), algo->getSamplesNum())
    , baseAlgo(std::move(algo))
    , itersNumHeuristicProbGoodEnoughModel(itersNumHeuristicProbGoodEnoughModel)
    , itersNumHeuristicNotNoiseProb(itersNumHeuristicNotNoiseProb)
{
}

template<class Model, class Data, class Sample>
std::pair<std::unique_ptr<Model>, Data> RansacItersNumHeuristicDecorator<Model, Data, Sample>
    ::runRansac(const Data& data)
{
    this->itersNum = calculateItersNumEstimation();
    baseAlgo->setItersNum(this->itersNum);
    return baseAlgo->runRansac(data);
}

template<class Model, class Data, class Sample>
std::vector<Sample> RansacItersNumHeuristicDecorator<Model, Data, Sample>
    ::getSamplesRandomly(const Data& data)
{
    return baseAlgo->getSamplesRandomly(data);
}

template<class Model, class Data, class Sample>
uint32_t RansacItersNumHeuristicDecorator<Model, Data, Sample>::calculateItersNumEstimation() const
{
    double itersNumDouble = std::log10(1 - itersNumHeuristicProbGoodEnoughModel)
                            / std::log10(1 - std::pow(itersNumHeuristicNotNoiseProb, this->samplesNum));
    return static_cast<uint32_t>(itersNumDouble);
}

} // namespace algorithm
} // namespace improc
} // namespace model
