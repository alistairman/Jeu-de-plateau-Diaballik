#ifndef VIEW_H
#define VIEW_H

//#include "Game.h"
#include "Observer.h"

//using namespace GameSpace;    // rnvs : comm

namespace GameSpace {// rnvs : ajout
class Game;// rnvs : ajout
}// rnvs : ajout

#include <string>   // rnvs : ajout

namespace ViewSpace {

/**
 * @brief The View class
 * this class represent the view of the game
 * and extend the observer class of the model
 */
class View : public ObserverSpace::Observer{

private:
    /**
     * @brief game_
     * this attribute represent the model game
     */
    // Game & game_;// rnvs : comm
    GameSpace::Game & game_;// rnvs : ajout
    int countPasse;
    int countMove;

public:
    /**
     * @brief update
     * this is a method from the observer class to update itself when a change happend in observable class
     */
    void update() const override;

    /**
     * @brief View
     * this is the constructor of view of game
     * @param game the game from the view will be build
     */
    // View(Game & game);// rnvs : comm
    View(GameSpace::Game & game);// rnvs : ajout

    ~View() override;

    /**
     * @brief addPlayers
     * this method called to add new player to the game
     */
    void addPlayers();

    /**
     * @brief getAction
     * this method take the action type by the player on board
     */
    void getAction();

    /**
     * @brief getWinner
     * this method show the winner of the game in consol
     */
    void getWinner();

private:

    /**
     * @brief showCommand
     * this method show how the player must play
     */
    void showCommand();

    /**
     * @brief checkAction
     * this method check if the enter of player is uselly or not
     * @param action the string represent an action
     * @return true if the string match an valid action
     */
    // bool checkAction(string action);// rnvs : comm
    bool checkAction(std::string action);// rnvs : ajout

    /**
     * @brief playAction
     * this method make the action typed by the player
     * @param action the string of action typed by the player
     * @param countMove the number of move action done by a player
     * @param countPasse the number of passe action done by a player
     */
    // void playAction(string action,int & countMove, int & countPasse);// rnvs : comm
    void playAction(std::string action,int & countMove, int & countPasse);// rnvs : ajout
};

}



#endif // VIEW_H
