#include <view/mainwindow.h>
#include <QApplication>

#include <iostream>
#include <unistd.h>

#include <model/ImageMatchingService.hpp>
#include <controller/MainController.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    model::ImageMatchingService imageMatchingService;
    controller::MainController controller(w, imageMatchingService);

    w.show();
    return a.exec();
}
