#-------------------------------------------------
#
# Project created by QtCreator 2019-05-20T09:36:45
#
#-------------------------------------------------

QT       += core gui

TARGET = TEST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QT += serialport

include(../../src/qextserialport.pri)
