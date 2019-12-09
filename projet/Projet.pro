    #-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T08:37:58
#
#-------------------------------------------------

QT       += core
QT      += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cgserveur.cpp \
    cgps.cpp \
    cgpio.cpp

HEADERS  += mainwindow.h \
    cgserveur.h \
    cgps.h \
    cgpio.h \
    piface.h

FORMS    += mainwindow.ui

LIBS += ./piface.o
