
#include <iostream>
//#include <ostream>

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

void Piece::passe(Piece piece){
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

void Piece::toString(){
    cout << static_cast<int>(color_) << endl;
}

bool Piece::getBool(){
    return ball_;
}

void Piece::setBool(bool b){
    ball_ = b;
}

}



