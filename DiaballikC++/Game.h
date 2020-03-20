#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Board.h"
#include "Players.h"

using namespace BoardSpace;
using namespace PlayersSpace;


namespace GameSpace {


class Game{

private:
    Board board_;
    Players player1_;
    Players player2_;
    Players  currentPlayer_ = player1_;

public:

    Game(unsigned x, unsigned y,string p1, string p2);
    void welcome();
    void getPlayer1();
    void getPlayer2();
    void start(); // a definir
    void showBoard();
    Players getCurrentPlayer();
    void swapPlayer();
    bool isOver(); // a definir
    Players getWinner();// a definir
    void restart(); // a definir
    void move(unsigned x, unsigned y); // a definir
    bool checkPasse(unsigned x,unsigned y, unsigned a, unsigned b); // a definir

};

}

#endif // GAME_H
