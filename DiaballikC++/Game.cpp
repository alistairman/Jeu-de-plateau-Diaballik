
#include <iostream>
#include "Game.h"


namespace GameSpace {

using namespace std;

Game::Game(unsigned width, unsigned height):
    board_ (Board(width,height)),
    currentPlayer_ (Players("",Color::NO)),
    winner_(Players("",Color::NO))
{}

bool Game::isPossibleToAdd(){
    return players_.size()<2;
}

void Game::addPlayer(string player){
    if(players_.size()==0){
        players_.push_back(Players(player,Color::BLACK));
    }
    else{
        players_.push_back(Players(player,Color::WHITE));
    }
    currentPlayer_ = players_.front();

}

Players Game::getCurrentPlayer(){
    return currentPlayer_;
}

void Game::swapPlayer(){
    if(currentPlayer_.getName() == players_.front().getName()){
        currentPlayer_ = players_.back();

    }else{
        currentPlayer_ = players_.front();
    }
}

void Game::start(){

    board_.initBoard();
    cout << "game started : " << endl;
    showBoard();
}

void Game::showBoard(){
    cout << endl;
    cout << "Board : " << endl;
    board_.showBoard(cout);
    cout << endl;
}


bool Game::isOver(){
    bool finish = false;
    for(unsigned i=0; i< board_.getWidth(); i++){
        if(board_.getPiece(0,i).getColor()==Color::WHITE && board_.getPiece(0,i).isInside()){
            finish = true;
            winner_ = players_.back();
        }
         if(board_.getPiece(6,i).getColor()==Color::BLACK && board_.getPiece(6,i).isInside()){
            finish = true;
            winner_ = players_.front();
        }
    }
    return finish;
}

Players Game::getWinner(){
    return  winner_;
}

bool Game::antiGame(Players currentPlayer){

    bool find = true;

        Piece opPiece = Piece(Color::NO);
        unsigned x = 0;
        unsigned limit = 1;
        unsigned count = 0;

        for (unsigned i=0; i<board_.getWidth(); i++){
            if(board_.isInsideBall(i,0) & board_.getPiece(i,0).getColor()==getOppoColor(currentPlayer)){
                opPiece = board_.getPiece(i,0);
                x = i;
            }
        }


        while (find & limit < board_.getHeight()){
            if(board_.getPiece(x-1,limit-1).getColor()==currentPlayer.getColor()){
                count++;
            }


            if(board_.getPiece(x-1,limit).getColor() ==  opPiece.getColor()){
                x = x-1;
                limit++;
            }
            else if (board_.getPiece(x+1,limit).getColor() == opPiece.getColor()){
                x = x+1;
                limit++;
            }

            else if (board_.getPiece(x,limit).getColor() == opPiece.getColor()){
                limit ++;
            }
            else{
                find = false;
            }

        }

    return  find ;

}

Color Game::getOppoColor(Players currentPlayer){
    if (currentPlayer.getColor() == players_.front().getColor()){
        return players_.back().getColor();
    }else{
        return players_.front().getColor();
    }
}


void Game::restart(){
    start();
}

void Game::play(unsigned int ox, unsigned int oy, unsigned int dx, unsigned int dy){
    board_.move(ox,oy,dx,dy,currentPlayer_.getColor());
}


void Game::passe(unsigned int dx, unsigned int dy, int ox, int oy){

    if(checkPasse(dx,dy,ox,oy)){
        board_.passe(dx,dy,ox,oy);
    }

}


void Game::action(string action){

    if (action=="passe") {
        unsigned dx = currentPlayer_.play();
        unsigned dy = currentPlayer_.play();
        int ox = 0;
        int oy = 0;

        for(int i=0; i< board_.getWidth(); i++){
            for(int j=0; j<board_.getHeight(); j++){
                if(board_.getPiece(i,j).getColor()==currentPlayer_.getColor() && board_.getPiece(i,j).isInside()){
                    ox=i;
                    oy=j;
                }
            }
        }
        passe(dx,dy,ox,oy);

    }

    if(action =="move"){
        unsigned ox = currentPlayer_.play();
        unsigned oy = currentPlayer_.play();
        unsigned dx = currentPlayer_.play();
        unsigned dy = currentPlayer_.play();
        if(checkMove(ox,oy,dx,dy)){
            play(ox,oy,dx,dy);
        }
    }

}

bool Game::checkMove(unsigned int ox, unsigned int oy, unsigned int dx, unsigned int dy){
    bool ok = false;
    if(ox>=0 & ox<board_.getWidth() & oy >= 0 & oy <board_.getHeight() & dx>=0 & dx <board_.getWidth() & dy >=0 & dy < board_.getHeight()){
        if((dx==ox-1 & dy ==oy) || (dx==ox & dy==oy+1) || (dx==ox+1 & dy==oy) || (dx==ox & dy==oy-1)){
            ok = true;
        }
        else{
           cout << " pas a coté de l'origine " << endl;
        }
    }
    else{
        cout << " en dehors du perimettre " << endl;
    }
    return ok;
}

bool Game::checkPasse( int dx,  int dy, int ox, int oy){
    bool ok = false;
    Piece p = Piece(Color::NO);

    if(ox<dx & oy < dy){
        p = direction(ox,oy,+1,+1);
    }

    if(ox<dx & oy>dy){
        p = direction(ox,oy,+1,-1);
    }

    if(ox>dx & oy>dy){
        p = direction(ox,oy,-1,-1);
    }

    if(ox>dx & oy<dy){
        p = direction(ox,oy,-1,+1);
    }

   if(p.getColor()==currentPlayer_.getColor()){
       ok=true;
   }

   return ok;

}

Piece Game::direction(int ox, int oy, int width, int height){
    int directionWidth = ox+width;
    int directionHeight = oy+height;

    while(directionWidth >= 0 & directionWidth < board_.getWidth() & directionHeight >= 0 & directionHeight < board_.getHeight()
            & board_.getPiece(directionWidth,directionHeight).getColor()!=currentPlayer_.getColor()){
        directionWidth += width;
        directionHeight += height;
    }
    return board_.getPiece(directionWidth,directionHeight);
}



}
