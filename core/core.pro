#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T18:44:15
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += core.cpp

HEADERS += core.h\
        core_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
