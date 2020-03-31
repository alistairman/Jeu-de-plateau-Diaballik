#ifndef PLAYERS_H
#define PLAYERS_H

#include<string>
#include "Color.h"

using namespace std;

namespace PlayersSpace {

/**
 * @brief The Players class
 * this class represent the player of the game
 */
class Players{

private:
    /**
     * @brief name_
     * this attribute represent the name of the player
     */
    string name_;

    /**
     * @brief color_
     * this attribute represent the color of the player in the game
     */
    Color color_;

public:
    /**
     * @brief Players
     * this method is a constructor of the player class
     * @param name the string represent the name of the player
     * @param color the value of the color of the player
     */
    Players(string name, Color color);

    /**
     * @brief getName
     * this method make the string name accessile
     * @return the string of the name
     */
    string getName();

    /**
     * @brief afficheName
     * @param c the ostream will conteint the name of the player
     * @return the ostream that will show the name of the player
     */
    ostream & afficheName(ostream & c);

    /**
     * @brief play
     * this method get the value input by the player
     */
    int play(istream & c);

    /**
     * @brief getColor
     * this method make the color of the player accessible
     * @return the color of the player
     */
    Color getColor();
    };

}

#endif // PLAYERS_H
