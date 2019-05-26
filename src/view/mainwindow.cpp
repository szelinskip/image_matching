#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdint>

#include <QPalette>
#include <QBitmap>
#include <QPainter>
#include <QFileDialog>

#include <controller/MainController.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setController(controller::MainController* controller)
{
    this->controller = controller;
}

void MainWindow::paintImagesWithMatchingPoints(const MatchingPointsPairs& matchingPoints)
{
    QImage imageA(QString::fromStdString(controller->getImageAPath()));
    QImage imageB(QString::fromStdString(controller->getImageBPath()));

    QImage combinedImage(imageA.width() + imageB.width(), imageA.height(), QImage::Format_RGB32);
    QPainter painter;
    painter.begin(&combinedImage);
    painter.drawImage(0, 0, imageA);
    painter.drawImage(imageA.width(), 0, imageB);
    painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
    drawMatchingPointsLines(painter, matchingPoints, imageA.width());
    painter.end();
    QPixmap pixmap = QPixmap::fromImage(combinedImage);

    imageLabel = std::make_unique<QLabel>();
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(pixmap);

    ui->imageScrollArea->setBackgroundRole(QPalette::Dark);
    ui->imageScrollArea->setWidget(imageLabel.get());
    ui->imageScrollArea->resize(ui->imageScrollArea->width(), combinedImage.height() + 20);
}

void MainWindow::initialize()
{
    // ???
}

void MainWindow::drawImageA(const QString& /*imageAPath*/)
{
}

void MainWindow::drawImageB(const QString& /*imageBPath*/)
{
}

void MainWindow::drawMatchingPointsLines(QPainter& painter,
                                         const MatchingPointsPairs& matchingPoints,
                                         const int32_t xOffset)
{
    for(auto& pointsPair : matchingPoints)
    {
        int32_t aX = static_cast<int32_t>(pointsPair.first.getX());
        int32_t aY = static_cast<int32_t>(pointsPair.first.getY());

        int32_t bX = static_cast<int32_t>(pointsPair.second.getX()) + xOffset;
        int32_t bY = static_cast<int32_t>(pointsPair.second.getY());

        painter.drawLine(aX, aY, bX, bY);
    }
}

void MainWindow::on_imageASelectionBtn_clicked()
{
    QString imageAPath = getFilenameViaDialog();
    controller->setImageAPath(imageAPath.toStdString());
    drawImageA(imageAPath);
}

void MainWindow::on_imageBSelectionBtn_clicked()
{
    QString imageBPath = getFilenameViaDialog();
    controller->setImageBPath(imageBPath.toStdString());
    drawImageB(imageBPath);
}

QString MainWindow::getFilenameViaDialog()
{
    return QFileDialog::getOpenFileName(this, "Select PNG image", "../images/");
}

void MainWindow::on_runMatchingBtn_clicked()
{
    std::string neighborhoodSizeStr = ui->neighborhoodSizeTextEdit->toPlainText().toStdString();
    std::string neighborhoodConsistencyThresholdStr =
        ui->neighborhoodConsistencyThresholdTextEdit->toPlainText().toStdString();
    controller->runMatching(neighborhoodSizeStr, neighborhoodConsistencyThresholdStr);
}
