#ifndef DEF_BALL
#define DEF_BALL

#include <iostream>
#include <ostream>
#include "Piece.h"

#include "Color.h"

//using namespace PieceSpace;


namespace BallSpace {


class Ball{

    private:
        Color color_;
        //Piece * piece_;
        //Ball ball;

    public:
        Ball(Color color);
        Ball();
        Color getColor();
};

}


#endif // HEADERS_H
