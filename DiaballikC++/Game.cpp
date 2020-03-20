
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
}

void Game::start(){
    board_.initBoard();
    getPlayer1();
    getPlayer2();
    cout << " entrez x : ";
    int x = player1_.play();
    cout << " player 1 joue :" << x << endl;


}

void Game::showBoard(){
    board_.showBoard(cout);
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
    return true;
}

}


