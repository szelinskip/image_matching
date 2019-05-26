#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QPalette>
#include <QBitmap>
#include <QPainter>

#include <memory>
#include <vector>

#include <helpers/Point.hpp>

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
    void paintImagesWithMatchingPoints(const MatchingPointsPairs& matchingPoints);

private slots:
    void on_imageASelectionBtn_clicked();
    void on_imageBSelectionBtn_clicked();

    void on_runMatchingBtn_clicked();

private:
    void initialize();
    void loadImage();
    QString getFilenameViaDialog();
    void drawImageA(const QString& imageAPath);
    void drawImageB(const QString& imageBPath);
    void drawMatchingPointsLines(QPainter& painter,
                                 const MatchingPointsPairs& matchingPoints,
                                 const int32_t xOffset);

    Ui::MainWindow *ui;
    controller::MainController* controller;

    std::unique_ptr<QLabel> imageLabel;
};

#endif // MAINWINDOW_H
