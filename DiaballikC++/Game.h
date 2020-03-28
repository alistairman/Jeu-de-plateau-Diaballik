#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include "Observable.h"
#include "Board.h"
#include "Players.h"

using namespace BoardSpace;
using namespace PlayersSpace;
//using namespace ObservableSpace;


namespace GameSpace {

//class Observable;

class Game {

private:
    Board board_;
    list<Players> players_;
    Players  currentPlayer_;
    Players winner_;

public:

    Game(unsigned x, unsigned y);
    //void welcome();
    bool isPossibleToAdd();
    void addPlayer(string player);
    void start(); // a finir en dernier avec la logique de jeu
    void showBoard();
    Players getCurrentPlayer();
    void swapPlayer();
    bool isOver();
    Players getWinner();
    void restart();
    bool antiGame(Players currentPlayer);
    Color getOppoColor(Players currentPlayer);
    void play(unsigned ox,unsigned oy, unsigned dx, unsigned dy);
    void action(string action);
    void passe(unsigned dx, unsigned dy,int ox,int oy);
    bool checkMove(unsigned x,unsigned y, unsigned a, unsigned b);
    bool checkPasse(int dx, int dy,int ox, int oy);
    Piece direction(int x, int y, int width, int height);

};

}

#endif // GAME_H
