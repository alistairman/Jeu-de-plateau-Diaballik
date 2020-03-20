#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Piece.h"

using namespace std;
using namespace PieceSpace;

namespace BoardSpace {


class Board{
private:
    unsigned width_;
    unsigned height_;
    vector < vector <Piece> >  board_;

public:

    Board(unsigned width, unsigned height);
    Piece getPiece(unsigned x, unsigned y);
    void addPiece(Piece p);
    bool isInside(unsigned x, unsigned y);
    void initBoard();
    ostream & showBoard (ostream & c);
};

}

#endif // BOARD_H
