#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <ostream>

#include "Color.h"
#include "Ball.h"

//using namespace BallSpace;

namespace PieceSpace {

//using namespace BallSpace;

class Piece{

private:
    Color color_;
    bool ball_;
    //Ball ball_;
    //Ball * ball_ = nullptr;
public:
    Piece (Color color);
    bool isInside();
    void passe(Piece & piece);
    Color getColor();

};

}

#endif // PIECE_H
