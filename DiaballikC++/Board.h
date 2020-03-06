#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
using namespace PieceSpace;

namespace BoardSpace {


class Board{
private:
    vector < vector <Piece> >  board_;
    unsigned width_;
    unsigned height_;

public:
    Board(unsigned width, unsigned height);
    Piece & getPiece(unsigned x, unsigned y);
    void addPiece(Piece p);
    bool isInside(unsigned x, unsigned y);
};

}

#endif // BOARD_H
