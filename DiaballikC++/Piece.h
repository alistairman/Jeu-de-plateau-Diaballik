#ifndef PIECE_H
#define PIECE_H


//#include <iostream>
//#include <ostream>

#include "Color.h"

namespace PieceSpace {

class Piece{

private:
    Color color_;
    bool ball_;
    //Ball ball_;
    //Ball * ball_ = nullptr;
public:
    Piece (Color color);
    bool isInside();
    void passe(Piece piece);
    Color getColor();
    void setColor(Color color);
    void toString();
    bool getBool();
    void setBool(bool b);

};

}

#endif // PIECE_H
