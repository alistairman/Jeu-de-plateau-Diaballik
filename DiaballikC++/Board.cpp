
#include "Board.h"
#include <iostream>
#include <ostream>
#include <vector>

namespace BoardSpace {

using namespace std;

Board::Board(unsigned width,unsigned height){
        width_ = width;
        height_ = height;

        for(unsigned i=0; i<width; i++){
            for(unsigned j=0; j<height; j++){
                board_[i][j] = Piece(Color::NO);
            }

        }
}

Piece & Board::getPiece(unsigned x, unsigned y){
    return board_[x][y];
}

void Board::addPiece(Piece p){

}


bool Board::isInside(unsigned x, unsigned y){
    if(x>=0 && x<width_ && y>=0 && y<height_){
        return board_[x][y].getColor() != Color::NO;
    }
}

}
