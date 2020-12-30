#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T17:49:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetSE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tableau.cpp \
    processus.cpp \
    fifo.cpp \
    pcte.cpp \
    priorite.cpp \
    tourniquet.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    tableau.h \
    processus.h \
    fifo.h \
    pcte.h \
    priorite.h \
    tourniquet.h \
    form.h

FORMS    += mainwindow.ui \
    tableau.ui \
    processus.ui \
    fifo.ui \
    pcte.ui \
    priorite.ui \
    tourniquet.ui \
    form.ui
