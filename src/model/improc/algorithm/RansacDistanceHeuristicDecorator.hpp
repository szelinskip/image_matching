#pragma once

#include <cstdint>
#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

#include "Ransac.hpp"
#include <utils/MathUtils.hpp>

namespace model {
namespace improc {
namespace algorithm {

template<class Model, class Data = typename Model::Data, class Sample = typename Data::Sample>
class RansacDistanceHeuristicDecorator : public RansacAlgo<Model, Data, Sample>
{
public:

    using RansacAlgoPtr = std::unique_ptr<RansacAlgo<Model, Data, Sample>>;

    RansacDistanceHeuristicDecorator(RansacAlgoPtr&& baseAlgo,
                                     const double lowerDistanceBound,
                                     const double upperDistanceBound);

    virtual std::vector<Sample> getSamplesRandomly(const Data& data) override;

protected:
    std::vector<Sample> getHeuristicBasedSamples(const Data& data);
    std::vector<std::pair<uint32_t, Sample>> filterSamples(
        const std::vector<std::pair<uint32_t, Sample>>& samplesToFilter,
        const Sample& sampleToCompareDistance);

    RansacAlgoPtr baseAlgo;
    double lowerDistanceBound;
    double upperDistanceBound;
};

template<class Model, class Data, class Sample>
RansacDistanceHeuristicDecorator<Model, Data, Sample>::RansacDistanceHeuristicDecorator(
    RansacAlgoPtr&& baseAlgo, const double lowerDistanceBound, const double upperDistanceBound)
    : RansacAlgo<Model, Data, Sample>(baseAlgo->getErrorThreshold(), baseAlgo->getItersNum(), baseAlgo->getSamplesNum())
    , baseAlgo(std::move(baseAlgo))
    , lowerDistanceBound(lowerDistanceBound)
    , upperDistanceBound(upperDistanceBound)
{
}

template<class Model, class Data, class Sample>
std::vector<Sample> RansacDistanceHeuristicDecorator<Model, Data, Sample>::getSamplesRandomly(const Data& data)
{
    std::vector<Sample> heuristcBasedSamples = getHeuristicBasedSamples(data);
    if(!heuristcBasedSamples.empty())
        return heuristcBasedSamples;
    else
        return baseAlgo->getSamplesRandomly(data);
}

template<class Model, class Data, class Sample>
std::vector<Sample> RansacDistanceHeuristicDecorator<Model, Data, Sample>::getHeuristicBasedSamples(
    const Data& data)
{
    std::unordered_set<uint32_t> usedIndices;
    usedIndices.reserve(this->samplesNum);

    std::vector<Sample> samples;
    samples.reserve(this->samplesNum);

    std::vector<Sample> dataAsSamplesVector = data.getDataAsSamplesVec();

    std::vector<std::pair<uint32_t, Sample>> samplesWithAbsoluteIndex;
    samplesWithAbsoluteIndex.reserve(dataAsSamplesVector.size());
    uint32_t absoluteIndex = 0u;
    std::for_each(dataAsSamplesVector.cbegin(), dataAsSamplesVector.cend(),
                  [&samplesWithAbsoluteIndex, &absoluteIndex](const auto& sample)
                  {
                      samplesWithAbsoluteIndex.emplace_back(absoluteIndex, sample);
                      absoluteIndex++;
                  });

    uint32_t i = 0u;
    while(usedIndices.size() < this->samplesNum)
    {
        if(i > 0)
            samplesWithAbsoluteIndex = filterSamples(samplesWithAbsoluteIndex, samples[i - 1]);

        if(samplesWithAbsoluteIndex.size() < usedIndices.size() + 1)
        {
            return {};
        }

        std::uniform_int_distribution<uint32_t>::param_type distParam(0u, samplesWithAbsoluteIndex.size() - 1);
        this->uintDis.param(distParam);
        uint32_t index = this->uintDis(this->gen);
        if(usedIndices.find(samplesWithAbsoluteIndex[index].first) == usedIndices.end())
        {
            usedIndices.insert(samplesWithAbsoluteIndex[index].first);
            samples.push_back(data.getSample(samplesWithAbsoluteIndex[index].first));
            i++;
        }
    }

    return samples;
}

template<class Model, class Data, class Sample>
std::vector<std::pair<uint32_t, Sample> > RansacDistanceHeuristicDecorator<Model, Data, Sample>
    ::filterSamples(const std::vector<std::pair<uint32_t, Sample>>& samplesToFilter,
                    const Sample& sampleToCompareDistance)
{
    std::vector<std::pair<uint32_t, Sample>> filtered;
    std::copy_if(samplesToFilter.cbegin(), samplesToFilter.cend(), std::back_inserter(filtered),
                 [&](const auto& sampleIndexPair)
                 {
                     double distanceBetweenFirstPointsInPair =
                         utils::math::euclideanDistance(sampleToCompareDistance.first,
                                                        sampleIndexPair.second.first);

                     bool firstPointInPairOk = distanceBetweenFirstPointsInPair > lowerDistanceBound
                                               && distanceBetweenFirstPointsInPair < upperDistanceBound;

                     if(!firstPointInPairOk)
                         return false;

                     double distanceBetweenSecondPointsInPair =
                         utils::math::euclideanDistance(sampleToCompareDistance.second,
                                                        sampleIndexPair.second.second);

                     return distanceBetweenSecondPointsInPair > lowerDistanceBound
                            && distanceBetweenSecondPointsInPair < upperDistanceBound;
                 });

    return filtered;
}

} // namespace algorithm
} // namespace improc
} // namespace model
