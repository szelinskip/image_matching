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
        $$PWD/model/improc/matcher/ImageMatcher.cpp \
        $$PWD/model/improc/matcher/NeighborhoodConsistencyMatcher.cpp \
        $$PWD/model/improc/matcher/RansacMatcher.cpp \
        $$PWD/model/improc/matcher/Matcher.cpp \
        $$PWD/model/improc/matcher/MatcherFactory.cpp \
        \
        $$PWD/model/improc/algorithm/NeighborhoodConsistency.cpp \
        $$PWD/model/improc/algorithm/PerspectiveTransformationRansac.cpp \
        $$PWD/model/improc/algorithm/AffineTransformationRansac.cpp \
        $$PWD/model/improc/algorithm/Ransac.cpp \
        $$PWD/model/improc/algorithm/RansacFactory.cpp \
        \
        $$PWD/model/improc/algorithm/transformation/Transformation.cpp \
        $$PWD/model/improc/algorithm/transformation/AffineTransformation.cpp \
        $$PWD/model/improc/algorithm/transformation/PerspectiveTransformation.cpp \
        $$PWD/model/improc/algorithm/transformation/MatrixData.cpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModel.cpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModelAffine.cpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModelPerspective.cpp \
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
        $$PWD/model/ImageMatchingParams.hpp \
        \
        $$PWD/model/improc/CharacteristicPoint.hpp \
        $$PWD/model/improc/ImageDescription.hpp \
        $$PWD/model/improc/HarrisSiftExtractor.hpp \
        \
        $$PWD/model/improc/loader/CharacteristicPointsLoader.hpp \
        \
        $$PWD/model/improc/matcher/ImageMatcher.hpp \
        $$PWD/model/improc/matcher/MutualNearestNeighbor.hpp \
        $$PWD/model/improc/matcher/NeighborhoodConsistencyMatcher.hpp \
        $$PWD/model/improc/matcher/RansacMatcher.hpp \
        $$PWD/model/improc/matcher/Matcher.hpp \
        $$PWD/model/improc/matcher/MatcherFactory.hpp \
        \
        $$PWD/model/improc/algorithm/NeighborhoodConsistency.hpp \
        $$PWD/model/improc/algorithm/PerspectiveTransformationRansac.hpp \
        $$PWD/model/improc/algorithm/AffineTransformationRansac.hpp \
        $$PWD/model/improc/algorithm/Ransac.hpp \
        $$PWD/model/improc/algorithm/RansacAlgo.hpp \
        $$PWD/model/improc/algorithm/RansacDistanceHeuristicDecorator.hpp \
        $$PWD/model/improc/algorithm/RansacItersNumHeuristicDecorator.hpp \
        $$PWD/model/improc/algorithm/RansacFactory.hpp \
        \
        $$PWD/model/improc/algorithm/transformation/Transformation.hpp \
        $$PWD/model/improc/algorithm/transformation/AffineTransformation.hpp \
        $$PWD/model/improc/algorithm/transformation/PerspectiveTransformation.hpp \
        $$PWD/model/improc/algorithm/transformation/MatrixData.hpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModel.hpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModelAffine.hpp \
        $$PWD/model/improc/algorithm/transformation/TransformationModelPerspective.hpp \
        \
        $$PWD/controller/MainController.hpp \
        $$PWD/controller/RawImageMatchingParams.hpp \
        \
        $$PWD/helpers/Point.hpp \
        \
        $$PWD/utils/MathUtils.hpp \
        $$PWD/utils/StringUtils.hpp
