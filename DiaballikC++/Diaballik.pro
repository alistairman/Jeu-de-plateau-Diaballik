TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c99\
        -pedantic-errors
SOURCES += \
        Ball.cpp \
        Board.cpp \
        Piece.cpp \
        Players.cpp \
        main.cpp

HEADERS += \
    Ball.h \
    Board.h \
    Color.h \
    Piece.h \
    Players.h
