
#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

#include "Game.h"
#include "Observable.h"


namespace GameSpace  {

using namespace std;
using namespace ObservableSpace;


Game::Game(unsigned width, unsigned height):
    board_ (Board(width,height)),
    currentPlayer_ (Players("",Color::NO)),
    winner_("")
{}

Game::~Game(){
    for(Observer * o: observers_){
        delete [] o;
    }
}

Players Game::getPlayer(unsigned i){
    if(i==1) return players_.front();
    else return players_.back();
}

bool Game::isPossibleToAdd(){
    return players_.size()<2;
}

void Game::addPlayers(list<Players> player){

    if(player.size()==0){
       cout << "pas assez de jouer" << endl;
    }
    else{

        for(Players p : player){
            players_.push_back(p);
        }
    }
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
    /**if(antiGame(currentPlayer_)){
        winner_ = currentPlayer_.getName();
    }*/
}

void Game::start(){
    if(!isPossibleToAdd()){
        board_.initBoard();
        currentPlayer_ = players_.front();
        cout << endl;
        cout << "game started : " << endl;
    }
    notifyObservers();
}

ostream & Game::showBoard(ostream & c){
   return board_.showBoard(c);
}

Piece Game::getPiece(unsigned i, unsigned j){
    return board_.getPiece(i,j);
}

void Game::showTable(QTableWidget *table){
    board_.showTable(table);
}

bool Game::isOver(){
    bool finish = false;
    if(winner_==""){
        for(unsigned i=0; i< board_.getWidth(); i++){
            if(board_.getPiece(0,i).getColor()==Color::WHITE && board_.getPiece(0,i).isInside()){
                finish = true;
                winner_ = players_.back().getName();
            }
             if(board_.getPiece(6,i).getColor()==Color::BLACK && board_.getPiece(6,i).isInside()){
                finish = true;
                winner_ = players_.front().getName();
            }
        }
    }
    else finish=true;
    return  finish;
}

string Game::getWinner(){
    return  winner_;
}

bool Game::overAntigame(unsigned i, unsigned j){
    bool ok = false;
    if(getPiece(i,j).getColor()==Color::BLACK){
        while (static_cast<int>(i)>=0) {
            if(getPiece(i,j).getColor()==Color::WHITE){
                ok = true;
            }
            i--;
        }
    }
    else{
        while (i<board_.getWidth()) {
            if(getPiece(i,j).getColor()==Color::BLACK){
                ok = true;
            }
            i++;
        }
    }
    return ok;
}

int Game::meetOpposite(unsigned i, unsigned j){
    if(getPiece(i,j).getColor()==Color::BLACK & getPiece(i+1,j).getColor()==Color::WHITE) return 1;
    else if(getPiece(i,j).getColor()==Color::WHITE & getPiece(i-1,j).getColor()==Color::BLACK) return 1;
    else return 0;
}

bool Game::antiGame(Players currentPlayer){

    bool find = true;
    unsigned indice = 0;
    unsigned j=0;
    Color color = getOppoColor(currentPlayer);
    int countMeetOpposite = 0;

    for(unsigned i=0;i<board_.getWidth();i++){
        if(getPiece(i,0).getColor()==color){
            indice = i;
        }
    }

    while (find && j<board_.getHeight() & indice<board_.getWidth() & static_cast<int>(indice)>=0)  {
        countMeetOpposite = meetOpposite(indice,j);
        if(getPiece(indice,j).getColor()!=color || overAntigame(indice,j)){
            return find=false;

        }
        else{
            j++;
            if(getPiece(indice,j).getColor()==color){
                j++;
            }
            else if(getPiece(indice-1,j).getColor()==color){
                indice--;
                j++;
            }
            else if(getPiece(indice+1,j).getColor()==color){
                indice++;
                j++;
            }
        }
    }
    return  find && countMeetOpposite>2;
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

void Game::move(unsigned ox,unsigned oy,unsigned dx,unsigned dy){
    cout << currentPlayer_.getName() << endl;
    cout << "current color :" << static_cast<std::underlying_type<Color>::type>(currentPlayer_.getColor()) << endl;
    board_.move(ox,oy,dx,dy,currentPlayer_.getColor());
    notifyObservers();
}


void Game::passe(unsigned ox, unsigned oy, unsigned dx,unsigned dy){
    board_.passe(ox,oy,dx,dy,currentPlayer_);
    notifyObservers();
}

void Game::registerObserver(Observer * observer) {
    observers_.insert(observer);
}

void Game::unregisterObserver(Observer * observer){
    observers_.erase(observer);
}

void Game::notifyObservers(){
    for(Observer * o : observers_){
        o->update();
    }
}


}

