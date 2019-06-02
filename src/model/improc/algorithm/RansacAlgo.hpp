#pragma once

#include <cstdint>
#include <memory>
#include <random>
#include <unordered_set>
#include <utility>
#include <vector>

namespace model {
namespace improc {
namespace algorithm {

template<class Model, class Data = typename Model::Data, class Sample = typename Data::Sample>
class RansacAlgo
{
public:
    RansacAlgo(const double errorThreshold, const uint32_t itersNum, const uint32_t samplesNum);
    virtual ~RansacAlgo() = default;

    RansacAlgo() = delete;
    RansacAlgo(const RansacAlgo&) = delete;
    RansacAlgo& operator=(const RansacAlgo&) = delete;
    RansacAlgo(RansacAlgo&&) = delete;
    RansacAlgo& operator=(RansacAlgo&&) = delete;

    std::pair<std::unique_ptr<Model>, Data> runRansac(const Data& data);
    std::vector<Sample> getSamplesRandomly(const Data& data);

protected:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<uint32_t> uintDis;

    double errorThreshold;
    uint32_t itersNum;
    uint32_t samplesNum;
};

template<class Model, class Data, class Sample>
RansacAlgo<Model, Data, Sample>::RansacAlgo(const double errorThreshold,
                                            const uint32_t itersNum,
                                            const uint32_t samplesNum)
    : rd()
    , gen(rd())
    , errorThreshold(errorThreshold)
    , itersNum(itersNum)
    , samplesNum(samplesNum)
{
}

template<class Model, class Data, class Sample>
std::pair<std::unique_ptr<Model>, Data> RansacAlgo<Model, Data, Sample>::runRansac(const Data& data)
{
    uint32_t bestScore = 0u;
    std::pair<std::unique_ptr<Model>, Data> bestModelConsensus;

    for(auto i = 0u; i < itersNum; i++)
    {
        std::vector<Sample> samples = getSamplesRandomly(data);
        std::unique_ptr<Model> model = std::make_unique<Model>(samples);

        uint32_t score = 0u;

        Data consensus;
        std::vector<double> errorVec = model->getErrorVec(data);
        for(auto i = 0u; i < errorVec.size(); i++)
        {
            if(errorVec[i] < errorThreshold)
            {
                score++;
                consensus.addSample(data.getSample(i));
            }
        }

        if(score > bestScore)
        {
            bestScore = score;
            bestModelConsensus.first = std::move(model);
            bestModelConsensus.second = std::move(consensus);
        }
    }

    return bestModelConsensus;
}

template<class Model, class Data, class Sample>
std::vector<Sample> RansacAlgo<Model, Data, Sample>::getSamplesRandomly(const Data& data)
{
    std::uniform_int_distribution<uint32_t>::param_type distParam(0u, data.size() - 1);
    uintDis.param(distParam);

    std::unordered_set<uint32_t> usedIndices;
    usedIndices.reserve(samplesNum);

    std::vector<Sample> samples;
    samples.reserve(samplesNum);

    while(usedIndices.size() < samplesNum)
    {
        uint32_t index = uintDis(gen);
        if(usedIndices.find(index) == usedIndices.end())
        {
            usedIndices.insert(index);
            samples.push_back(data.getSample(index));
        }
    }

    return samples;
}

} // namespace algorithm
} // namespace improc
} // namespace model
