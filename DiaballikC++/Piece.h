#ifndef PIECE_H
#define PIECE_H

#include "Color.h"
#include "Ball.h"

namespace Piece {

using namespace BallSpace;

class Piece{

private:
    Color color_;
    Ball ball_;
public:
    Piece (Color color);
    bool isInside();
    void passe(Piece & piece);

};

}

#endif // PIECE_H
