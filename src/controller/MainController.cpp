#include "MainController.hpp"

#include <clocale>

#include <view/mainwindow.h>
#include <model/ImageMatchingService.hpp>
#include <model/ImageMatchingParams.hpp>

namespace controller {

MainController::MainController(MainWindow& mainWindow, model::ImageMatchingService& imageMatchingService)
    : mainWindow(mainWindow)
    , imageMatchingService(imageMatchingService)
{
    std::setlocale(LC_ALL, "C");
    mainWindow.setController(this);
    imageMatchingService.setController(this);
}

MainController::~MainController() = default;

void MainController::setImageAPath(const std::string& imageAPath)
{
    imageMatchingService.setImageAPath(imageAPath);
}

std::string MainController::getImageAPath() const
{
    return imageMatchingService.getImageAPath();
}

void MainController::setImageBPath(const std::string& imageBPath)
{
    imageMatchingService.setImageBPath(imageBPath);
}

std::string MainController::getImageBPath() const
{
    return imageMatchingService.getImageBPath();
}

void MainController::runMatching(const RawImageMatchingParams& rawParams)
{
    model::ImageMatchingParams params;
    params.matchingMethod = rawParams.selectedMatcherMethod;
    if(!rawParams.neighborhoodSizeStr.empty())
        params.neighborhoodSize = static_cast<uint32_t>(std::stoi(rawParams.neighborhoodSizeStr));
    if(!rawParams.neighborhoodConsistencyThresholdStr.empty())
        params.neighborhoodConsistencyThreshold = std::stod(rawParams.neighborhoodConsistencyThresholdStr);
    if(!rawParams.errorThresholdStr.empty())
        params.errorThreshold = std::stod(rawParams.errorThresholdStr);
    if(!rawParams.itersNumStr.empty())
        params.itersNum = static_cast<uint32_t>(std::stoi(rawParams.itersNumStr));
    params.distanceHeuristicEnabled = rawParams.distanceHeuristicSelected;
    if(!rawParams.distanceHeuristcLowerBoundStr.empty())
        params.distanceHeuristcLowerBound = std::stod(rawParams.distanceHeuristcLowerBoundStr);
    if(!rawParams.distanceHeuristcUpperBoundStr.empty())
        params.distanceHeuristcUpperBound = std::stod(rawParams.distanceHeuristcUpperBoundStr);
    params.itersNumEstimationHeuristicEnabled = rawParams.itersNumEstimationHeuristicSelected;
    if(!rawParams.itersNumHeuristicProbGoodEnoughModelStr.empty())
        params.itersNumHeuristicProbGoodEnoughModel = std::stod(rawParams.itersNumHeuristicProbGoodEnoughModelStr);
    if(!rawParams.itersNumHeuristicNotNoiseProbStr.empty())
        params.itersNumHeuristicNotNoiseProb = std::stod(rawParams.itersNumHeuristicNotNoiseProbStr);

    MatchingPointsPairs matchingPoints = imageMatchingService.matchImages(params);
    mainWindow.paintImagesWithMatchingPoints(matchingPoints);
}

} // namespace controller
