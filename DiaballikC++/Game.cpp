
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
            if(board_.getPiece(x,x-1).getColor()==currentPlayer.getColor()){
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
    board_.move(ox,oy,dx,dy);
    showBoard();
}

}


