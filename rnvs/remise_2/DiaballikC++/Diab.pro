TEMPLATE = app
CONFIG += console # c++14   # rnvs : comm : ko
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors\
                -std=c++17\
                -Wall
SOURCES += \
        Board.cpp \
        Game.cpp \
        Piece.cpp \
        Players.cpp \
        View.cpp \
        main.cpp

HEADERS += \
    Board.h \
    Color.h \
    Game.h \
    Observable.h \
    Observer.h \
    Piece.h \
    Players.h \
    View.h
