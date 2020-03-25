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
    Piece b = Piece(Color::NO);
    if(board_[x][y].getColor()!=Color::NO){
            b = board_[x][y];
        }
    return b;
}


bool Board::isInside(unsigned x, unsigned y){
    return board_[x][y].getBool()!=false;
}

void Board::initBoard(){
    for(unsigned i=0; i<height_; i++ ){
        for(unsigned j=0; j<width_; j++){
            board_[i][j] = Piece(Color::NO);
        }
    }

    for(unsigned i=0;i<height_;i++){
        board_[0][i] = Piece(Color::BLACK);
        board_[6][i] = Piece(Color::WHITE);
    }

    board_[0][3].setBool();
    board_[6][3].setBool();
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

unsigned Board::getWidth(){
    return width_;
}

unsigned Board::getHeight(){
    return height_;
}

void Board::move(unsigned ox, unsigned oy, unsigned dx, unsigned dy, Color currentColor){

    if(board_[dx][dy].getColor() == Color::NO & board_[ox][oy].getColor()== currentColor && board_[ox][oy].getBool()!=true){
        board_[dx][dy] = board_[ox][oy];
        board_[ox][oy] = Piece(Color::NO);
    }
}

void Board::passe(unsigned int dx, unsigned int dy, Color color){
    if(!isInside(dx,dy) && board_[dx][dy].getColor()==color){
    for(unsigned i=0; i<width_; i++){
        for(unsigned j=0; j<height_; j++){
            if(board_[i][j].getColor()==color & isInside(i,j)){

                    board_[dx][dy].setBool();
                    board_[i][j].setBool();
                }
            }
        }
    }
}


}




