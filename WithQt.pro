#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T20:20:02
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WithQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -LC:\SFML\lib

CONFIG(release, debug|release) : LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release) : LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += C:\SFML\include
DEPENDPATH += C:\SFML\include

#INCLUDEPATH += C:\Qt\platf\SFML\include
#DEPENDPATH += C:\Qt\platf\SFML\include

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    howplay.cpp \
    setting.cpp \
    jsondata.cpp \
    view.cpp

HEADERS += \
        mainwindow.h \
    howplay.h \
    enemy.h \
    mainer.h \
    map.h \
    player.h \
    view.h \
    setting.h \
    jsondata.h

FORMS += \
        mainwindow.ui \
    howplay.ui \
    setting.ui \
    jsondata.ui

RESOURCES += \
    resource.qrc
