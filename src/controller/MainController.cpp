#include "MainController.hpp"

#include <view/mainwindow.h>
#include <model/ImageMatchingService.hpp>

namespace controller {

MainController::MainController(MainWindow& mainWindow, model::ImageMatchingService& imageMatchingService)
    : mainWindow(mainWindow)
    , imageMatchingService(imageMatchingService)
{
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

void MainController::runMatching()
{
    MatchingPointsPairs matchingPoints = imageMatchingService.matchImages();
    mainWindow.paintImagesWithMatchingPoints(matchingPoints);
}

} // namespace controller
