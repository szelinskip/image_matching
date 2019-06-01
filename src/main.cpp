#include <view/mainwindow.h>
#include <QApplication>

#include <model/ImageMatchingService.hpp>
#include <controller/MainController.hpp>

//#include <model/improc/transformation/MatrixData.hpp>
//#include <model/improc/transformation/TransformationModelAffine.hpp>
//#include <vector>
//#include <model/improc/matcher/RansacAlgo.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    model::ImageMatchingService imageMatchingService;
    controller::MainController controller(w, imageMatchingService);

    w.show();
    return a.exec();

//    using namespace model::improc;

//    Eigen::Matrix<double, 4, 3> matrix;

//    matrix << 6, 2, 3,
//              2, 8, 9,
//              7, 5, 3,
//              1, 6, 7;

//    MatrixData matrixData(std::move(matrix));

//    using namespace helpers;
//    std::vector<std::pair<Point, Point>> pairs = {
//        {Point{3, 4}, Point{5, 7}},
//        {Point{2, 3}, Point{4, 8}},
//        {Point{7, 11}, Point{12, 6}}
//    };

//    TransformationModelAffine model(pairs);

//    model.getErrorVec(matrixData);

//    matcher::RansacAlgo<TransformationModelAffine> ransac(10, 20, 3);

//    return 0;
}
