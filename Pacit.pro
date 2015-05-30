#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T00:03:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman
TEMPLATE = app
RC_FILE = pacscii.rc

CONFIG += c++11

SOURCES += main.cpp\
    Game.cpp \
    Player.cpp \
    Debug.cpp \
    Bullet.cpp \
    Teleport.cpp \
    Wall.cpp \
    Floor.cpp \
    Enemy.cpp \
    Powerup.cpp

HEADERS  += \
    Game.h \
    Player.h \
    Debug.h \
    Bullet.h \
    Teleport.h \
    Wall.h \
    Floor.h \
    Enemy.h \
    Powerup.h

FORMS    +=

RESOURCES += \
    images.qrc
