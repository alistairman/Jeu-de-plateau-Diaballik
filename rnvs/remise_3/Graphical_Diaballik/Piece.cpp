
#include <iostream>
#include "Piece.h"

using namespace std;

namespace PieceSpace {


Piece::Piece(Color color):
    color_(color),
    ball_(false)
{}


bool Piece::isInside(){
    return ball_ == true;
}

void Piece::passe(Piece & piece){
    piece.setBool();
    this->setBool();
}

Color Piece::getColor(){
    return color_;
}


void Piece::setBool(){
    if(ball_==true) ball_=false;
    else ball_=true;
}

void Piece::setColor(Color color){
    color_ = color;
}

}



