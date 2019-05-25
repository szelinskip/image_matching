#pragma once

#include <string>

namespace model {
namespace improc {

class HarrisSiftExtractor
{
public:
    HarrisSiftExtractor();
    ~HarrisSiftExtractor();

    HarrisSiftExtractor(const HarrisSiftExtractor&) = delete;
    HarrisSiftExtractor& operator=(const HarrisSiftExtractor&) = delete;
    HarrisSiftExtractor(HarrisSiftExtractor&&) = delete;
    HarrisSiftExtractor& operator=(HarrisSiftExtractor&&) = delete;

    std::string extractImageFeatures(const std::string& imagePath) const;

private:
    std::string buildCommand(const std::string& imagePath) const;

    const std::string extractorPath;
};

} // namespace improc
} // namespace model
