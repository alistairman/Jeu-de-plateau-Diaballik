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

Piece Board::getPiece(int x, int y){
    Piece b = Piece(Color::NO);
    if(board_[x][y].getColor()!=Color::NO){
            b = board_[x][y];
        }
    return b;
}


bool Board::isInsideBall(unsigned x, unsigned y){
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

    if(board_[dx][dy].getColor() == Color::NO & board_[ox][oy].getColor()== currentColor && !board_[ox][oy].isInside()){
        board_[dx][dy] = board_[ox][oy];
        board_[ox][oy] = Piece(Color::NO);
    }
}

void Board::passe(unsigned int dx, unsigned int dy, int ox, int oy){
    if(board_[dx][dy].getColor()==board_[ox][oy].getColor()  && !isInsideBall(dx,dy)){
        board_[ox][oy].passe(board_[dx][dy]);
    }
}

Piece Board::getBall(Players p){

    for(int i=0; i< width_; i++){
        for(int j=0; height_; j++){
            if(getPiece(i,j).getColor()==p.getColor() && isInsideBall(i,j)){
               return getPiece(i,j);
            }
        }
    }
}


}




