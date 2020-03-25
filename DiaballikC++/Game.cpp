
#include <iostream>
//#include <ostream>
#include "Game.h"


namespace GameSpace {

using namespace std;

Game::Game(unsigned width, unsigned height,string a, string b):
    board_ (Board(width,height)),
    player1_ (Players(a,Color::BLACK)),
    player2_ (Players(b, Color::WHITE)),
    currentPlayer_ (player1_)
{}

void Game::welcome(){
    cout << " =======================" << endl;
    cout << " Bienvenu Dans DIABALLIK " << endl;
    cout << " =======================" << endl;
    cout << endl;
}

Players Game::getCurrentPlayer(){
    return currentPlayer_;
}

void Game::swapPlayer(){
    if(currentPlayer_.getName() == player1_.getName()){
        currentPlayer_ = player2_;

    }else{
        currentPlayer_ = player1_;
    }
    cout << "currentPlayer : " << currentPlayer_.getName() << endl;
}

void Game::start(){

    board_.initBoard();
    getPlayer1();
    getPlayer2();
    showBoard();
    cout << "game started : " << endl;

}

void Game::showBoard(){
    cout << endl;
    cout << "Board : " << endl;
    board_.showBoard(cout);
    cout << endl;
}

void Game::getPlayer1(){
    cout << "Player 1 : " ;
    player1_.afficheName(cout);
}

void Game::getPlayer2(){
    cout << "Player 2 : " ;
    player2_.afficheName(cout);
}

bool Game::isOver(){
    bool finish = false;
    for(unsigned i=0; i< board_.getWidth(); i++){
        if(board_.getPiece(0,i).getColor()==Color::WHITE & board_.getPiece(0,i).getBool()==true
            || board_.getPiece(6,i).getColor()==Color::BLACK & board_.getPiece(6,i).getBool()==true){
            finish = true;
        }
    }
    return finish;
}

bool Game::antiGame(Players currentPlayer){

    bool find = true;

        Piece opPiece = Piece(Color::NO);
        unsigned x = 0;
        unsigned limit = 1;
        unsigned count = 0;

        for (unsigned i=0; i<board_.getWidth(); i++){
            if(board_.isInside(i,0) & board_.getPiece(i,0).getColor()==getOppoColor(currentPlayer)){
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
    if (currentPlayer.getColor() == player1_.getColor()){
        return player2_.getColor();
    }else{
        return player1_.getColor();
    }
}




Players Game::getWinner(){
    Players winner = Players("",Color::NO);
    if(!isOver()){
        for(unsigned i=0; i< board_.getWidth(); i++){
            if(board_.getPiece(0,i).getColor()==player2_.getColor() & board_.getPiece(0,i).getBool()==true){
                winner = player2_;
            }
            if(board_.getPiece(6,i).getColor()==player1_.getColor() & board_.getPiece(6,i).getBool()==true){
                winner = player1_;
            }
        }
    }
    return  winner;
}

void Game::restart(){
    start();
}

void Game::play(unsigned int ox, unsigned int oy, unsigned int dx, unsigned int dy){

    board_.move(ox,oy,dx,dy,currentPlayer_.getColor());
    //showBoard();
}


void Game::passe(unsigned int dx, unsigned int dy){
    board_.passe(dx,dy,currentPlayer_.getColor());
}


void Game::action(string action){

    if (action=="passe") {
        passe(currentPlayer_.play(),currentPlayer_.play());

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

}
