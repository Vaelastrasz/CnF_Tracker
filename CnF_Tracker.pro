#-------------------------------------------------
#
# Project created by QtCreator 2021-04-21T19:45:52
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CnF_Tracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbmanager.cpp

HEADERS  += mainwindow.h \
    dbmanager.h \
    globalscope.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc
