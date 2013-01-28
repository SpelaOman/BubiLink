#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T04:41:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BubiLink
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addlink.cpp \
    global.cpp \
    add_profile.cpp \
    add_campaign.cpp

HEADERS  += mainwindow.h \
    addlink.h \
    global.h \
    add_profile.h \
    add_campaign.h

FORMS    += mainwindow.ui \
    addlink.ui \
    add_profile.ui \
    add_campaign.ui

QT += sql
