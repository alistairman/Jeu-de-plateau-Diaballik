#ifndef PIECE_H
#define PIECE_H

// #include <iostream>  // rnvs : comm
#include "Color.h"

// using namespace std; // rnvs : comm

namespace PieceSpace {

/**
 * @brief The Piece class
 * this class represent a piece of the board
 */
class Piece{

private:

    /**
     * @brief color_ the color of the piece
     */
    Color color_;

    /**
     * @brief ball_ the boolean if the piece conteint the ball of the player
     */
    bool ball_;

public:

    /**
     * @brief Piece this method is the constructor of the piece
     * @param color the color of the piece
     */
    Piece (Color color);

    /**
     * @brief isInside
     * this method check if this piece conteint de ball
     * @return true if the ball is inside
     */
    bool isInside();

    /**
     * @brief passe
     * this method can this piece make passe if he conteint the ball
     * @param piece the piece that will receive the ball
     */
    void passe(Piece & piece);

    /**
     * @brief getColor
     * this method make the color accessible
     * @return the color of the piece
     */
    Color getColor();

    /**
     * @brief getBool
     * this method make the boolean accessible if the piece conteint the ball
     * @return the ball value of the piece
     */
    bool getBool();

    /**
     * @brief setBool
     * this method change the value of the boolean ball
     */
    void setBool();

};

}

#endif // PIECE_H
