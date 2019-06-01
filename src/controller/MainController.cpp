#include "MainController.hpp"

#include <clocale>

#include <view/mainwindow.h>
#include <model/ImageMatchingService.hpp>

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

void MainController::runMatching(const std::string& neighborhoodSizeStr, const std::string& neighborhoodConsistencyThresholdStr)
{
    uint32_t neighborhoodSize = static_cast<uint32_t>(std::stoi(neighborhoodSizeStr));
    double neighborhoodConsistencyThreshold = std::stod(neighborhoodConsistencyThresholdStr);
    MatchingPointsPairs matchingPoints = imageMatchingService.matchImages(
        neighborhoodSize, neighborhoodConsistencyThreshold);
    mainWindow.paintImagesWithMatchingPoints(matchingPoints);
}

} // namespace controller
