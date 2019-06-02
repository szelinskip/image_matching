#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdint>

#include <QPalette>
#include <QBitmap>
#include <QPainter>
#include <QFileDialog>

#include <controller/MainController.hpp>
#include <controller/RawImageMatchingParams.hpp>

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

void MainWindow::drawImages(const std::function<void(QPainter&, const int32_t)>& additionalPainting)
{
    QImage imageA(QString::fromStdString(controller->getImageAPath()));
    QImage imageB(QString::fromStdString(controller->getImageBPath()));

    QImage combinedImage(imageA.width() + imageB.width(), imageA.height(), QImage::Format_RGB32);
    QPainter painter;
    painter.begin(&combinedImage);
    painter.drawImage(0, 0, imageA);
    painter.drawImage(imageA.width(), 0, imageB);
    painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
    additionalPainting(painter, imageA.width());
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

void MainWindow::paintImagesWithMatchingPoints(const MatchingPointsPairs& matchingPoints)
{
    drawImages([&](QPainter& painter, const int32_t offset)
               {
                   drawMatchingPointsLines(painter, matchingPoints, offset);
               });
}

void MainWindow::initialize()
{
    // ???
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

void MainWindow::on_imagesSelectionBtn_clicked()
{
    QString imageAPath = getFilenameViaDialog("Image A");
    controller->setImageAPath(imageAPath.toStdString());
    QString imageBPath = getFilenameViaDialog("Image B");
    controller->setImageBPath(imageBPath.toStdString());
    drawImages([](auto&, auto){});
}

QString MainWindow::getFilenameViaDialog(const QString& info)
{
    return QFileDialog::getOpenFileName(this, "Select " + info + " - PNG image", "../images/");
}

void MainWindow::on_runMatchingBtn_clicked()
{
    controller::RawImageMatchingParams params;
    params.selectedMatcherMethod = ui->matchingMethodComboBox->currentText().toStdString();
    params.neighborhoodSizeStr = ui->neighborhoodSizeTextEdit->toPlainText().toStdString();
    params.neighborhoodConsistencyThresholdStr =
        ui->neighborhoodConsistencyThresholdTextEdit->toPlainText().toStdString();
    params.errorThresholdStr = ui->errorThresholdTextEdit->toPlainText().toStdString();
    params.itersNumStr = ui->itersNumTextEdit->toPlainText().toStdString();
    params.distanceHeuristicSelected = ui->distanceHeuristicCheckBox->isChecked();
    params.distanceHeuristcLowerBoundStr = ui->distanceLowerBoundTextEdit->toPlainText().toStdString();
    params.distanceHeuristcUpperBoundStr = ui->distanceUpperBoundTextEdit->toPlainText().toStdString();
    params.itersNumEstimationHeuristicSelected = ui->itersNumEstimationHeuristicCheckBox->isChecked();
    params.itersNumHeuristicProbGoodEnoughModelStr = ui->pProbabilityTextEdit->toPlainText().toStdString();
    params.itersNumHeuristicNotNoiseProbStr = ui->wProbabilityTextEdit->toPlainText().toStdString();
    controller->runMatching(params);
}
