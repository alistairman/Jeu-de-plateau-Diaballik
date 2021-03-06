#include <iostream>
#include <vector>
#include "Board.h"
#include <QLabel>
#include <QPixmap>


using namespace std;

namespace BoardSpace {


Board::Board(unsigned width,unsigned height):
        width_(width),
        height_(height),
        board_ (vector<vector<Piece>>(width_,vector<Piece>(height_,Piece(Color::NO))))
{}

Piece & Board::getPiece(unsigned x, unsigned y){

    if(static_cast<int>(x)>=0 && x<width_ && static_cast<int>(y)>= 0 && y <height_){
        return board_[x][y];
    }else{
        throw string(" données non valide ");
    }
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
            if(getPiece(i,j).isInside()){
                c <<" " << static_cast<std::underlying_type<Color>::type>(getPiece(i,j).getColor()) << "b";
                 //return board_[i][j].toString(c) << "b";
            }
            else{
                c <<" " << static_cast<std::underlying_type<Color>::type>(getPiece(i,j).getColor()) << " ";
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

bool Board::isInside(unsigned x, unsigned y){
    return getPiece(x,y).getColor() != Color::NO;
}

bool Board::isInsideBall(unsigned x, unsigned y){
    return getPiece(x,y).isInside();
}

bool Board::checkDistance(unsigned ox, unsigned oy, unsigned dx, unsigned dy){
    return (dx==ox-1 & dy ==oy) || (dx==ox & dy==oy+1) || (dx==ox+1 & dy==oy) || (dx==ox & dy==oy-1);
}

void Board::move(unsigned ox, unsigned oy, unsigned dx, unsigned dy,Color color){

    Color currentColor = getPiece(ox,oy).getColor();

    if(color==currentColor && checkMove(ox,oy, dx,dy)){
    getPiece(dx,dy).setColor(currentColor);
    getPiece(ox,oy).setColor(Color::NO);
    }
    else{
        throw string("impossible de deplacer le pion... ");
    }
}

bool Board::checkMove(unsigned ox, unsigned oy, unsigned dx, unsigned dy){
    cout << ox << oy << dx << dy << endl;
    if(!isInsideBall(ox,oy) & !isInside(dx,dy)){
        if(checkDistance(ox,oy,dx,dy)) return true;
        else throw string(" distance trop longue");
    }
    else{
       throw string(" Distance trop grande ou piece deja occupée ");
    }
}

void Board::passe(unsigned ox, unsigned oy, unsigned dx, unsigned dy,Players currentPlayer){

    if(checkPasse(ox,oy,dx,dy,currentPlayer)){
        getPiece(ox,oy).passe(getPiece(dx,dy));
    }
    else{
        throw string("passe non valide ");
    }
}

bool Board::checkPasse(unsigned ox, unsigned oy,unsigned dx, unsigned dy,Players currentPlayer){

    bool ok = false;
    if(getPiece(ox,oy).getColor()==currentPlayer.getColor() && getPiece(dx,dy).getColor()==currentPlayer.getColor()){
        if(direction(ox,oy,+1,+1,dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,static_cast<unsigned>(-1),static_cast<unsigned>(-1),dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,static_cast<unsigned>(-1),+1,dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,+1,static_cast<unsigned>(-1),dx,dy,currentPlayer)) ok = true;

        if(direction(ox,oy,0,+1,dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,0,static_cast<unsigned>(-1),dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,static_cast<unsigned>(-1),0,dx,dy,currentPlayer)) ok = true;
        if(direction(ox,oy,+1,0,dx,dy,currentPlayer)) ok = true;
    }
    return ok;
}

bool Board::direction(unsigned ox, unsigned oy, unsigned width, unsigned height,unsigned dx, unsigned dy,Players currentPlayer){
    unsigned directionWidth = ox+width;
    unsigned directionHeight = oy+height;
    bool valid = false;

    while(static_cast<int>(directionWidth) >= 0 && directionWidth < width_ && static_cast<int>(directionHeight) >= 0 &&
          directionHeight < height_){

        if(getPiece(directionWidth,directionHeight).getColor()!=Color::NO &&
           getPiece(directionWidth,directionHeight).getColor()!=currentPlayer.getColor()){
            break;
        }
        else if(directionWidth==dx && directionHeight==dy){
            valid = true;
            break;
        }

        directionWidth += width;
        directionHeight += height;
    }
    return  valid;
}

void Board::showTable(QTableWidget *table){

    int count = 1;

    for(unsigned i=0;i < height_;i++){
        for(unsigned j =0; j<width_; j++){

            QLabel *label = new QLabel();
            label->setAlignment(Qt::AlignCenter);

            if(count==1){
                label->setStyleSheet("background-color: bleu;");
                count = 2;
            }else{
                label->setStyleSheet("background-color: green;");
                count = 1;
            }

            if(board_[i][j].getColor()!=Color::NO){
                if(board_[i][j].getColor()==Color::BLACK){
                    if(board_[i][j].isInside()){

                        QPixmap pix = QPixmap("pionJBall.png");
                        label->setPixmap(pix);
                        table->setCellWidget(static_cast<int>(i),static_cast<int>(j),label);
                    }
                    else{
                        QPixmap pix = QPixmap("pionJaune.png");
                        label->setPixmap(pix);
                        table->setCellWidget(static_cast<int>(i),static_cast<int>(j),label);
                    }
                }
                else{
                    if(board_[i][j].isInside()){
                        QPixmap pix = QPixmap("pionRBall.png");
                        label->setPixmap(pix);
                        table->setCellWidget(static_cast<int>(i),static_cast<int>(j),label);
                    }
                    else{
                        QPixmap pix = QPixmap("pionRouge.png");
                        label->setPixmap(pix);
                        table->setCellWidget(static_cast<int>(i), static_cast<int>(j),label);
                    }
                }
            }
            else{
                table->setCellWidget(static_cast<int>(i),static_cast<int>(j),label);
            }
        }
    }
}

}
