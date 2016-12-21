TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    curvemontgomety.cpp

unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lgcrypt

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

HEADERS += \
    curvemontgomety.hpp \
    point.hpp
