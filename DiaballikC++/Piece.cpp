
#include "Piece.h"
#include "Ball.h"
#include <iostream>
#include <ostream>


using namespace std;
//using enum Color;

namespace PieceSpace {


Piece::Piece(Color color){
    color_ = color;
    ball_=false;
    //ball_ = Ball();
}


bool Piece::isInside(){
    return ball_ == true;
}

void Piece::passe(Piece & piece){
    if(!piece.isInside()){
        piece.ball_ = ball_;
        ball_ = false;

    }
    else{
        cout << "error ball is already get " << endl;
    }
}

Color Piece::getColor(){
    return color_;
}

}
