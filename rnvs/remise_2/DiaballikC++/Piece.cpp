
// #include <iostream>  // rnvs : comm
#include <string>   // rnvs : ajout
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
    if(!piece.isInside()){
        piece.setBool();
        this->setBool();

    }
    else{
        throw string ("error ball is already get ");
    }
}

Color Piece::getColor(){
    return color_;
}

bool Piece::getBool(){
    return ball_;
}

void Piece::setBool(){
    if(ball_==true){
        ball_=false;
    }else {
        ball_=true;
    }
}

}



