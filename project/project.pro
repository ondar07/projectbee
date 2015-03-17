#-------------------------------------------------
#
# Project created by QtCreator 2014-04-16T23:57:29
#
#-------------------------------------------------

QT       += core gui\
    multimedia \
    core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bee.cpp \
    beehive.cpp \
    queen.cpp \
    cell.cpp \
    worker.cpp \
    drone.cpp \
    scene_t.cpp \
    egg.cpp \
    mainqueen.cpp \
    egglist.cpp \
    honey.cpp

HEADERS  += mainwindow.h \
    cell.h \
    bee.h \
    beehive.h \
    queen.h \
    worker.h \
    drone.h \
    scene_t.h \
    egg.h \
    mainqueen.h \
    globalVariables.h \
    egglist.h \
    honey.h

FORMS    += mainwindow.ui

CONFIG += console \
    qt
