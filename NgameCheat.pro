#-------------------------------------------------
#
# Project created by QtCreator 2016-09-25T11:31:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NgameCheat
TEMPLATE = app
win32: LIBS += -luser32

SOURCES += main.cpp\
        mainwindow.cpp \
    mykeypress.cpp \
    readkey.cpp

HEADERS  += mainwindow.h \
    mykeypress.h \
    readkey.h

FORMS    += mainwindow.ui \
    readkey.ui

CONFIG += static
