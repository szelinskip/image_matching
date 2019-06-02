#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QPalette>
#include <QBitmap>
#include <QPainter>

#include <functional>
#include <memory>
#include <vector>

#include <helpers/Point.hpp>
#include <model/improc/matcher/MatchingResult.hpp>

namespace Ui {
class MainWindow;
}

namespace controller {
class MainController;
} // namespace controller

using helpers::Point;
using MatchingPointsPairs = std::vector<std::pair<Point, Point>>;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setController(controller::MainController* controller);
    void updateUiWithMatchingResult(const model::improc::matcher::MatchingResult& matchingResult);

private slots:
    void on_runMatchingBtn_clicked();
    void on_imagesSelectionBtn_clicked();

private:
    void initialize();
    void loadImage();
    QString getFilenameViaDialog(const QString& info);
    void drawImages(const std::function<void(QPainter&, const int32_t)>& additionalPainting);
    void paintImagesWithMatchingPoints(const MatchingPointsPairs& matchingPoints);
    void drawMatchingPointsLines(QPainter& painter,
                                 const MatchingPointsPairs& matchingPoints,
                                 const int32_t xOffset);

    Ui::MainWindow *ui;
    controller::MainController* controller;

    std::unique_ptr<QLabel> imageLabel;
};

#endif // MAINWINDOW_H
