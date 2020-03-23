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
    bool checkPasse(unsigned x,unsigned y, unsigned a, unsigned b); // a definir

};

}

#endif // GAME_H
