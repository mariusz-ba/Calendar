#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T18:30:01
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    event.cpp \
    eventdialog.cpp

HEADERS  += mainwindow.h \
    calendar.h \
    event.h \
    eventdialog.h
