
#include "Piece.h"

namespace Piece {
using namespace std;

Piece::Piece(Color color){
    color_ = color;
    ball_ = NULL;
}

bool Piece::isInside(){
    return ball_ != NULL;
}

void Piece::passe(Piece & piece){
    if(!piece.isInside()){
        piece.ball_ = ball_;
        ball_ = NULL;
    }
    else{
        cout << "error ball is already get " << endl;
    }
}

}
