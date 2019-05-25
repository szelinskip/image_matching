#include "HarrisSiftExtractor.hpp"

#include <stdlib.h>
#include <stdexcept>

namespace model {
namespace improc {

HarrisSiftExtractor::HarrisSiftExtractor()
    : extractorPath("../features_extractor/extract_features_32bit.ln")
{
}

HarrisSiftExtractor::~HarrisSiftExtractor() = default;

std::string HarrisSiftExtractor::extractImageFeatures(const std::string& imagePath) const
{
    std::string cmd = buildCommand(imagePath);
    int cmdStatus = system(cmd.c_str());
    if(cmdStatus != 0)
        throw std::runtime_error("Shell command execution error: " + cmd);
    return imagePath + ".haraff.sift";
}

std::string HarrisSiftExtractor::buildCommand(const std::string& imagePath) const
{
    return extractorPath + " -haraff -sift -i " + imagePath + " -DE";
    // return extractorPath + " -haraff -sift -i " + imagePath + " -DE > /dev/null";
}

} // namespace improc
} // namespace model
