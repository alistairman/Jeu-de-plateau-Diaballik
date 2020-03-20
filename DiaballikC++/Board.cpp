#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

namespace BoardSpace {



Board::Board(unsigned width,unsigned height):
        width_(width),
        height_(height),
        board_ (vector<vector<Piece>>(width_,vector<Piece>(height_,Piece(Color::NO))))

{}

Piece Board::getPiece(unsigned x, unsigned y){
    return board_[x][y];
}




bool Board::isInside(unsigned x, unsigned y){
    bool ok = false;
    int w = static_cast<int>(width_);
    int h = static_cast<int>(height_);
    if(x>=0 && x<w && y>=0 && y<h){
        if( board_[x][y].getColor() != Color::NO){
            ok = true;
        }
    }
    return ok;
}

void Board::initBoard(){
    for(unsigned i=0; i<height_; i++ ){
        board_[0][i] = Piece(Color::BLACK);
        board_[6][i] = Piece(Color::WHITE);
    }
    board_[0][3].setBool(true);
    board_[6][3].setBool(true);
}

ostream& Board::showBoard (ostream & c ){
    for(unsigned i=0; i<width_; i++){
        c << endl;
        for(unsigned j=0; j<height_; j++){
            if(board_[i][j].getBool()==true){
                c <<" " << static_cast<std::underlying_type<Color>::type>(board_[i][j].getColor()) << "b";
                //c <<" " << static_cast<bool>(board_[i][j].getBool());
            }
            else{
                c <<" " << static_cast<std::underlying_type<Color>::type>(board_[i][j].getColor()) << " ";
            }

        }
    }
    c << endl;
    return c;
}



}




