INCLUDEPATH += \
            /usr/include/eigen3/ \
            \
            $$PWD/ \
            $$PWD/model/ \
            $$PWD/model/improc/ \
            $$PWD/view/

SOURCES += \
        $$PWD/view/mainwindow.cpp \
        \
        $$PWD/model/ImageMatchingService.cpp \
        \
        $$PWD/model/improc/CharacteristicPoint.cpp \
        $$PWD/model/improc/ImageDescription.cpp \
        $$PWD/model/improc/HarrisSiftExtractor.cpp \
        \
        $$PWD/model/improc/loader/CharacteristicPointsLoader.cpp \
        \
        $$PWD/model/improc/matcher/MutualNearestNeighbor.cpp \
        $$PWD/model/improc/matcher/NeighborhoodConsistency.cpp \
        $$PWD/model/improc/matcher/ImageMatcher.cpp \
        \
        $$PWD/model/improc/transformation/Transformation.cpp \
        $$PWD/model/improc/transformation/AffineTransformation.cpp \
        $$PWD/model/improc/transformation/PerspectiveTransformation.cpp \
        $$PWD/model/improc/transformation/MatrixData.cpp \
        $$PWD/model/improc/transformation/TransformationModel.cpp \
        $$PWD/model/improc/transformation/TransformationModelAffine.cpp \
        $$PWD/model/improc/transformation/TransformationModelPerspective.cpp \
        \
        $$PWD/controller/MainController.cpp \
        \
        $$PWD/helpers/Point.cpp \
        \
        $$PWD/utils/MathUtils.cpp \
        $$PWD/utils/StringUtils.cpp \
        \
        $$PWD/main.cpp

HEADERS += \
        $$PWD/view/mainwindow.h \
        \
        $$PWD/model/ImageMatchingService.hpp \
        \
        $$PWD/model/improc/CharacteristicPoint.hpp \
        $$PWD/model/improc/ImageDescription.hpp \
        $$PWD/model/improc/HarrisSiftExtractor.hpp \
        \
        $$PWD/model/improc/loader/CharacteristicPointsLoader.hpp \
        \
        $$PWD/model/improc/matcher/MutualNearestNeighbor.hpp \
        $$PWD/model/improc/matcher/NeighborhoodConsistency.hpp \
        $$PWD/model/improc/matcher/ImageMatcher.hpp \
        $$PWD/model/improc/matcher/RansacAlgo.hpp \
        \
        $$PWD/model/improc/transformation/Transformation.hpp \
        $$PWD/model/improc/transformation/AffineTransformation.hpp \
        $$PWD/model/improc/transformation/PerspectiveTransformation.hpp \
        $$PWD/model/improc/transformation/MatrixData.hpp \
        $$PWD/model/improc/transformation/TransformationModel.hpp \
        $$PWD/model/improc/transformation/TransformationModelAffine.hpp \
        $$PWD/model/improc/transformation/TransformationModelPerspective.hpp \
        \
        $$PWD/controller/MainController.hpp \
        \
        $$PWD/helpers/Point.cpp \
        \
        $$PWD/utils/MathUtils.hpp \
        $$PWD/utils/StringUtils.hpp
