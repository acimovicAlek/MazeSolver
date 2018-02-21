#-------------------------------------------------
#
# Project created by dinko osmankovic
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeSolver
TEMPLATE = app

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    maze.cpp \
    mazesolver.cpp

HEADERS += \
        mainwindow.h \
    maze.h \
    mazesolver.h

FORMS += \
        mainwindow.ui



LIBS += -L$$PWD/../../../Documents/LogicToolbox/lib/ -llogictoolbox

INCLUDEPATH += $$PWD/../../../Documents/LogicToolbox/include
DEPENDPATH += $$PWD/../../../Documents/LogicToolbox/include

LIBS += -L$$PWD/../../../../../usr/lib/ -lcdt
LIBS += -L$$PWD/../../../../../usr/lib/ -lcgraph
LIBS += -L$$PWD/../../../../../usr/lib/ -lgvc
LIBS += -L$$PWD/../../../../../usr/lib/ -lpathplan

