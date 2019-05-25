#include <view/mainwindow.h>
#include <QApplication>

#include <iostream>
#include <unistd.h>

#include <model/ImageMatchingService.hpp>

int main(/*int argc, char *argv[]*/)
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    char buffer [500];
    memset(buffer, 0, 500);
    char* buff = getcwd(buffer, 500);
    if(buff == nullptr)
    {
        std::cout << "buff nullptr" << std::endl;
    }
    std::cout << "Hello world, cwd=" << buffer << std::endl;
    model::ImageMatchingService imageMatchingService;

    imageMatchingService.setImageAPath("../images/imageA.png");
    imageMatchingService.setImageBPath("../images/imageB.png");

    auto matching = imageMatchingService.matchImages();

    for(auto& match: matching)
    {
        std::cout << "pointA: (" << match.first.X() << "; " << match.first.Y()
                  << ") ; pointB: (" << match.second.X() << "; " << match.second.Y()
                  << ")" << std::endl;
    }

    return 0;
//    return a.exec();
}
