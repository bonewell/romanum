QT -= core gui

TARGET = RomanumCore
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

REALDIR = ../..

SOURCES += \
        $$REALDIR/core/romannumber.cpp \
        $$REALDIR/core/validator.cpp \
        $$REALDIR/core/converter.cpp

HEADERS += \
        $$REALDIR/core/romannumber.h \
        $$REALDIR/core/validator.h \
        $$REALDIR/core/converter.h
