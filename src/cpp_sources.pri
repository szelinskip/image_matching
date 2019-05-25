INCLUDEPATH += \
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
        \
        $$PWD/helpers/Point.cpp \
        \
        $$PWD/utils/MathUtils.cpp \
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
        $$PWD/model/improc/matcher/ImageMatcher.hpp \
        \
        $$PWD/helpers/Point.cpp \
        \
        $$PWD/utils/MathUtils.hpp
