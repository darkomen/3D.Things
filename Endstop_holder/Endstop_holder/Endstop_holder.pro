TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
LIBS +=  -lOOMLCore \
         -lOOMLComponents \
         -lOOMLParts

INCLUDEPATH += /usr/include/ooml

HEADERS += \
    config.h
