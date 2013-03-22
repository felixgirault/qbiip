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
    exception.cpp \
    note.cpp \
    frequencies.cpp \
    configurable.cpp \
    output/consoleoutput.cpp \
    input/consoleinput.cpp \
    output/networkoutput.cpp \
    input/networkinput.cpp \
    input/scoreinput.cpp \
    output/speakeroutput.cpp \
    input.cpp \
    output.cpp \
    application.cpp \
    streams.cpp

HEADERS += \
    exception.h \
    note.h \
    state.h \
    frequencies.h \
    factory.h \
    configurable.h \
    output/consoleoutput.h \
    input/consoleinput.h \
    output/networkoutput.h \
    input/networkinput.h \
    input/scoreinput.h \
    output/speakeroutput.h \
    input.h \
    output.h \
    application.h \
    streams.h

OTHER_FILES += \
    README.md \
    scores/mario.json \
    scores/tron.json \
    scores/win.json
