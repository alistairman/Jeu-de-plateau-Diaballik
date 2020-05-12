#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include "Observable.h"
#include "Board.h"
#include "Players.h"

using namespace BoardSpace;
using namespace PlayersSpace;
using namespace ObservableSpace;


namespace GameSpace{

/**
 * @brief The Game class
 * this class is the model of the game
 * and represent the observable class
 */
class Game : public ObservableSpace::Observable {

private:
    /**
     * @brief board_
     * this attribute represent the board of the game
     */
    Board board_;

    /**
     * @brief players_
     * this represent the list of the players
     */
    list<Players> players_;

    /**
     * @brief currentPlayer_
     * this attribute represent the current player
     */
    Players  currentPlayer_;

    /**
     * @brief winner_
     * this attribute represent the winner of the Game
     */
    Players winner_;

public:

    Game();

    /**
     * @brief Game
     * this is the constructor of the model
     * @param x this is the value of the length of the column
     * @param y this is the value of the length of the row
     */
    Game(int x, int y);

    /**
    * this method destroy the model of the game and make free all the allocate memories
    */
    ~Game() override;

    /**
     * @brief registerObserver
     * this method add a new observer to the list of the observer
     * @param observer the observer to register in the list of observer
     */
    void registerObserver(Observer * observer) override;

    /**
     * @brief unregisterObserver
     * this method delete an observer from the list of the observer registered
     * @param observer
     */
    void unregisterObserver(Observer *observer) override;

    /**
     * @brief notifyObservers
     * this method notity all the observer of this class
     */
    void notifyObservers() override;

    Players getPlayer(int i);

    /**
     * @brief isPossibleToAdd
     * this method check if is possible to add a new player
     * @return true if there is possible to add a new player
     */
    bool isPossibleToAdd();

    /**
     * @brief addPlayer
     * this method create and add a new player to the game
     * @param player the name of the new player to create
     */
    void addPlayers(list<Players> player);

    /**
     * @brief start
     * this method check if there is enaugth player and init the board to start the game
     */
    void start();

    /**
     * @brief showBoard
     * this method show the state of the board in consol
     * @param c the ostream wich show the board in consol
     * @return the ostream with the board to show
     */
    ostream & showBoard(ostream & c);

    /**
     * @brief getCurrentPlayer
     * this method make the current player accessible
     * @return the current player of the game
     */
    Players getCurrentPlayer();

    /**
     * @brief swapPlayer
     * this method change the current player after each turn
     */
    void swapPlayer();

    /**
     * @brief isOver
     * this method check if the game is over
     * and check if there was a antigame
     * @return true if the game is over by antigame or if a player win the game
     */
    bool isOver();

    /**
     * @brief getWinner
     * this method make the attribute winner accessible if the game is finish
     * @return the winner of the game
     */
    Players getWinner();

    /**
     * @brief restart
     * this method restart the game
     */
    void restart();

    /**
     * @brief antiGame
     * this method check if there is a anti game made by a player
     * @param currentPlayer the current player to check the anti game made by the opposite player
     * @return true if the opposite player made a anti game
     */
    bool antiGame(Players currentPlayer);

    /**
     * @brief getOppoColor
     * this method get the color of the opposite playe of the current player
     * @param currentPlayer the current player of the game
     * @return the color of the opposite player
     */
    Color getOppoColor(Players currentPlayer);

    /**
     * @brief move
     * this call the method move of the board to move a piece
     * @param ox the origin value of the specific row in the board
     * @param oy the origin value of the specific column in the board
     * @param dx the destination value of the specific row in the board
     * @param dy the destination value of the specific column in the board
     */
    void move(int ox,int oy, int dx, int dy);

    /**
     * @brief passe
     * this method call the passe method of the board to move the ball
     * @param dx the destination value of the specific row in the board
     * @param dy the destination value of the specific column in the board
     */
    void passe(unsigned ox, unsigned oy, int dx, int dy);

    Piece getPiece(int i, int j);

    void showTable(QTableWidget * table);


};

}

#endif // GAME_H
