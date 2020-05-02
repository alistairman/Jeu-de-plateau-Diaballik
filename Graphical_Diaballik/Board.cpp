#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

namespace BoardSpace {


Board::Board(int width,int height):
        width_(width),
        height_(height),
        board_ (vector<vector<Piece>>(width_,vector<Piece>(height_,Piece(Color::NO))))
{}

Piece Board::getPiece(int x, int y){
    return board_[x][y];
}


bool Board::isInsideBall(int x, int y){
    return board_[x][y].getBool()!=false;
}

void Board::initBoard(){
    for(int i=0; i<height_; i++ ){
        for(int j=0; j<width_; j++){
            board_[i][j] = Piece(Color::NO);
        }
    }

    for(int i=0;i<height_;i++){
        board_[0][i] = Piece(Color::BLACK);
        board_[6][i] = Piece(Color::WHITE);
    }

    board_[0][3].setBool();
    board_[6][3].setBool();
}

ostream& Board::showBoard (ostream & c ){
    for(int i=0; i<width_; i++){
        c << endl;
        for(int j=0; j<height_; j++){
            if(board_[i][j].getBool()==true){
                c <<" " << static_cast<std::underlying_type<Color>::type>(board_[i][j].getColor()) << "b";
                 //return board_[i][j].toString(c) << "b";
            }
            else{
                c <<" " << static_cast<std::underlying_type<Color>::type>(board_[i][j].getColor()) << " ";
            }

        }
    }
    c << endl;
    return c;
}

int Board::getWidth(){
    return width_;
}

int Board::getHeight(){
    return height_;
}

void Board::move(int ox, int oy, int dx, int dy, Color currentColor){
    if(checkMove(ox,oy,dx,dy)){
        if(board_[dx][dy].getColor() == Color::NO && board_[ox][oy].getColor()== currentColor && !board_[ox][oy].isInside()){
            board_[dx][dy] = board_[ox][oy];
            board_[ox][oy] = Piece(Color::NO);
        }
        else{
            throw string("impossible de deplacer le pion... ");
        }
    }

}

bool Board::checkMove(int ox, int oy, int dx, int dy){
    bool ok = false;
    if(ox>=0 & ox<width_ & oy >= 0 & oy <height_ & dx>=0 & dx <width_ & dy >=0 & dy < height_){
        if((dx==ox-1 & dy ==oy) || (dx==ox & dy==oy+1) || (dx==ox+1 & dy==oy) || (dx==ox & dy==oy-1)){
            ok = true;
        }
        else{
           throw string(" Distance trop grande ");
        }
    }
    else{
        throw string(" impossible de deplacer le pion hors du tableau ");
    }
    return ok;
}

void Board::passe(int dx, int dy,Players currentPlayer){
    int ox=0;
    int oy=0;

    for(int i=0;i<width_;i++){
        for(int j=0;j<height_;j++){
            if(currentPlayer.getColor() == board_[i][j].getColor() && board_[i][j].isInside()){
                ox = i;
                oy = j;
            }
        }
    }

    if(checkPasse(ox,oy,dx,dy,currentPlayer.getColor())){
        if(board_[dx][dy].getColor()==board_[ox][oy].getColor() && !isInsideBall(dx,dy)){
            board_[ox][oy].passe(board_[dx][dy]);
        }
        else{
            throw string("destination invalide ");
        }
    }
    else{
        throw string("passe non valide ");
    }
}

bool Board::checkPasse(int ox, int oy,int dx, int dy,Color color){
    bool ok = false;
    Piece p = Piece(Color::NO);

    if(ox<dx & oy < dy){
        p = direction(ox,oy,+1,+1,color);
    }

    if(ox<dx & oy>dy){
        p = direction(ox,oy,+1,-1,color);
    }

    if(ox>dx & oy>dy){
        p = direction(ox,oy,-1,-1,color);
    }

    if(ox>dx & oy<dy){
        p = direction(ox,oy,-1,+1,color);
    }

   if(p.getColor()==color){
       ok=true;
   }
   return ok;
}

Piece Board::direction(int ox, int oy, int width, int height,Color color){
    int directionWidth = ox+width;
    int directionHeight = oy+height;

    while(directionWidth >= 0 & directionWidth < width_ & directionHeight >= 0 & directionHeight < height_
            & board_[directionWidth][directionHeight].getColor()!=color){
        directionWidth += width;
        directionHeight += height;
    }
    return board_[directionWidth][directionHeight];
}

void Board::showTable(QTableWidget *table){

    for(int i=0;i < height_;i++){
        for(int j =0; j<width_; j++){
            if(board_[i][j].getColor() == Color::BLACK){
                QString test = QString::fromStdString("BLACK");
                table->setItem(i,j,new QTableWidgetItem(test));
            }
            if(board_[i][j].getColor() ==Color::WHITE){
                QString test = QString::fromStdString("WHITE");
                table->setItem(i,j,new QTableWidgetItem(test));
            }
        }
    }

}


}
