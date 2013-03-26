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
    application.cpp \
    ../core/exception.cpp \
    ../core/note.cpp \
    ../core/frequencies.cpp \
    ../core/configurable.cpp \
    ../core/output/consoleoutput.cpp \
    ../core/input/consoleinput.cpp \
    ../core/output/networkoutput.cpp \
    ../core/input/networkinput.cpp \
    ../core/input/scoreinput.cpp \
    ../core/output/speakeroutput.cpp \
    ../core/input.cpp \
    ../core/output.cpp \
    ../core/streams.cpp

HEADERS += \
    application.h \
    ../core/exception.h \
    ../core/note.h \
    ../core/state.h \
    ../core/frequencies.h \
    ../core/factory.h \
    ../core/configurable.h \
    ../core/output/consoleoutput.h \
    ../core/input/consoleinput.h \
    ../core/output/networkoutput.h \
    ../core/input/networkinput.h \
    ../core/input/scoreinput.h \
    ../core/output/speakeroutput.h \
    ../core/input.h \
    ../core/output.h \
    ../core/streams.h

