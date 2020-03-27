#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"
#include "Players.h"

using namespace std;
using namespace PieceSpace;
using namespace PlayersSpace;

namespace BoardSpace {


class Board{
private:
    unsigned width_;
    unsigned height_;
    vector < vector <Piece> >  board_;

public:

    Board(unsigned width, unsigned height);
    Piece getPiece(int x, int y);
    void addPiece(Piece p);
    bool isInsideBall(unsigned x, unsigned y);
    void initBoard();
    ostream & showBoard (ostream & c);
    unsigned getWidth();
    unsigned getHeight();
    void move(unsigned ox, unsigned oy, unsigned dx, unsigned dy, Color color);
    void passe(unsigned dx, unsigned dy, int ox, int oy);
    Piece getBall(Players p);
};

}

#endif // BOARD_H
