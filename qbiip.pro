#-------------------------------------------------
#
# Project created by QtCreator 2013-01-27T17:07:00
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = qbiip
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    biip.cpp \
    server.cpp \
    client.cpp \
    exception.cpp \
    note.cpp \
    consoleoutputter.cpp \
    speakeroutputter.cpp \
    networkoutputter.cpp

HEADERS += \
    biip.h \
    server.h \
    client.h \
    exception.h \
    note.h \
    outputter.h \
    consoleoutputter.h \
    speakeroutputter.h \
    networkoutputter.h

OTHER_FILES += \
    README.md
