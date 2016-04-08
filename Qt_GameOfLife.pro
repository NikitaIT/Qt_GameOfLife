#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T23:24:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_GameOfLife
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game_of_life.cpp

HEADERS  += mainwindow.h \
    game_of_life.h \
    qpaintwidget.h

FORMS    += mainwindow.ui
