include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        tst_soudnexencoding.h \
    soundex.h

SOURCES += \
        main.cpp

DISTFILES += \
    README.md
