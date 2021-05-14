TEMPLATE = app
QMAKE_LFLAGS += -static -static-libgcc -static-libstdc++ -lpthread
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ModulesKovalov.h
