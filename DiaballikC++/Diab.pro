TEMPLATE = app
CONFIG += console c++14
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
    Board_copy.h \
    Color.h \
    Game.h \
    Observable.h \
    Observer.h \
    Piece.h \
    Players.h \
    View.h



FORMS +=
