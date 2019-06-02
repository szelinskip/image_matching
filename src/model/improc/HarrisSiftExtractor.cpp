#include "HarrisSiftExtractor.hpp"

#include <regex>
#include <stdlib.h>
#include <stdexcept>

#include <utils/StringUtils.hpp>

namespace model {
namespace improc {

HarrisSiftExtractor::HarrisSiftExtractor()
    : extractorPath("../features_extractor/extract_features_32bit.ln")
{
}

HarrisSiftExtractor::~HarrisSiftExtractor() = default;

std::string HarrisSiftExtractor::extractImageFeatures(const std::string& imagePath) const
{
    std::string imagePathLocal = utils::str::replace(imagePath, " ", "\\ ");
    std::string cmd = buildCommand(imagePathLocal);
    int cmdStatus = system(cmd.c_str());
    if(cmdStatus != 0)
        throw std::runtime_error("Shell command execution error: " + cmd);
    std::string currPath = imagePathLocal + ".haraff.sift";
    auto slashPos = currPath.rfind("/");
    if(slashPos == std::string::npos)
        throw std::runtime_error("File path error: " + currPath);
    std::string dirPath = currPath.substr(0, slashPos + 1);
    std::string pathAfterMove = dirPath + "processing/" + currPath.substr(slashPos + 1);
    std::string mvCmd = "mv " + dirPath + "*.haraff* " + dirPath + "processing/ > /dev/null 2>&1";
    cmdStatus = system(mvCmd.c_str());
    if(cmdStatus != 0)
        throw std::runtime_error("File move error: " + cmd);
    return utils::str::replace(pathAfterMove, "\\ ", " ");
}

std::string HarrisSiftExtractor::buildCommand(const std::string& imagePath) const
{
    return extractorPath + " -haraff -sift -i " + imagePath + " -DE > /dev/null 2>&1";
    // return extractorPath + " -haraff -sift -i " + imagePath + " -DE > /dev/null";
}

} // namespace improc
} // namespace model
