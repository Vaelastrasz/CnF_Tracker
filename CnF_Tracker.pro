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
    dbmanager.cpp \
    sqltablemodel.cpp \
    insertrecord.cpp

HEADERS  += mainwindow.h \
    dbmanager.h \
    globalscope.h \
    sqltablemodel.h \
    insertrecord.h

FORMS    += mainwindow.ui \
    insertrecord.ui

RESOURCES += \
    resources/resources.qrc
