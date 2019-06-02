#pragma once

#include <string>
#include <vector>

#include "RawImageMatchingParams.hpp"
#include <helpers/Point.hpp>

class MainWindow;

namespace model{
class ImageMatchingService;
} // namespace model

namespace controller {

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class MainController
{
public:
    MainController(MainWindow& mainWindow, model::ImageMatchingService& imageMatchingService);
    ~MainController();

    MainController(const MainController&) = delete;
    MainController& operator=(const MainController&) = delete;
    MainController(MainController&&) = delete;
    MainController& operator=(MainController&&) = delete;

    void setImageAPath(const std::string& imageAPath);
    std::string getImageAPath() const;
    void setImageBPath(const std::string& imageBPath);
    std::string getImageBPath() const;
    void runMatching(const RawImageMatchingParams& rawParams);

private:
    MainWindow& mainWindow;
    model::ImageMatchingService& imageMatchingService;
};

} // namespace controller
