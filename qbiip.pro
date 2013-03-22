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
    consoleoutput.cpp \
    consoleinput.cpp \
    networkoutput.cpp \
    networkinput.cpp \
    scoreinput.cpp \
    speakeroutput.cpp \
    input.cpp \
    output.cpp \
    application.cpp

HEADERS += \
    exception.h \
    note.h \
    state.h \
    frequencies.h \
    factory.h \
    configurable.h \
    consoleoutput.h \
    consoleinput.h \
    networkoutput.h \
    networkinput.h \
    scoreinput.h \
    speakeroutput.h \
    input.h \
    output.h \
    application.h

OTHER_FILES += \
    README.md \
    scores/tron.json
