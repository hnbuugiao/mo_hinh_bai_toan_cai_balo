#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T17:55:26
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NienLuanTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphic.cpp \
    nhap.cpp \
    dohoa.cpp

HEADERS  += mainwindow.h \
    graphic.h \
    nhap.h \
    dohoa.h

FORMS    += mainwindow.ui \
    dohoa.ui \
    nhap.ui

RESOURCES += \
    Images.qrc
