#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"
#include "Players.h"
#include <QTableWidget>

using namespace std;
using namespace PieceSpace;
using namespace PlayersSpace;

namespace BoardSpace {

/**
 * @brief The Board class
 * this class represent the board of the game
 * with 7 row and 7 column
 */

class Board{

private:
    /**
     * @brief width_
     * the length of the column
     */
    int width_;

    /**
     * @brief height_
     * the length of the row
     */
    int height_;

    /**
     * @brief board_
     * the 2D board conteint pieces of the game
     */
    vector < vector <Piece> >  board_;

public:

    /**
     * @brief Board
     * the constructor of board with specific width and height size
     * @param width the length of the column
     * @param height the length of the row
     */
    Board(int width, int height);

    /**
     * @brief getPiece
     * this method avoid to get a piece in the specific position
     * @param x the width position of the piece
     * @param y the height position of the piece
     * @return piece in the x column et y row of the board
     */
    Piece getPiece(int x, int y);

    /**
     * @brief isInsideBall this method check if a piece in the specific position
     * conteint a ball
     * @param x the width position of the piece in the board
     * @param y the height position of the piece in the board
     * @return true if this piece conteint a ball
     */
    bool isInsideBall(int x, int y);

    /**
     * @brief initBoard
     * this method fil the board
     */
    void initBoard();

    /**
     * @brief showBoard
     * this method inject to the ostream the board to show
     * @param c represent the ostream
     * @return the ostream who that will show the board
     */
    ostream & showBoard (ostream & c);

    /**
     * @brief getWidth
     * this method make the attribute width accessible
     */
    int getWidth();

    /**
     * @brief getHeight
     * this method make the attribute height accessible
     */
    int getHeight();

    /**
     * @brief checkMove
     * this method check the move made by the player whith specific
     * position from and to of the piece
     * @param ox the origin  width position in the board
     * @param oy the origin height position in the board
     * @param dx the width destination position in the board
     * @param dy the height destination position in the board
     * @return true if the move is correct width rules of the game
     */
    bool checkMove(int ox,int oy, int dx, int dy);

    /**
     * @brief move
     * this method make a piece move from specific position to anothor position
     * @param ox the origin  width position in the board
     * @param oy the origin height position in the board
     * @param dx the width destination position in the board
     * @param dy the height destination position in the board
     * @param dy the height destination position in the board
     * @param color the piece color of the current player
     */
    void move(int ox, int oy, int dx, int dy, Color color);

    /**
     * @brief checkPasse
     * this method check if the a pass can be make
     * @param ox the origin  width position in the board
     * @param oy the origin height position in the board
     * @param dx the width destination position in the board
     * @param dy the height destination position in the board
     * @param color the piece color of the current player
     * @return true if the passe can be done according to the rules of the game
     */
    bool checkPasse(int ox, int oy, int dx, int dy,Color color);

    /**
     * @brief passe
     * this method move the ball of the player from to specific piece in specific position
     * @param dx the width destination position in the board
     * @param dy the height destination position in the board
     * @param currentPlayer the player who want to move the ball
     */
    void passe(int dx, int dy,Players currentPlayer);

    /**
     * @brief direction
     * this method make the both check method move from a position to the next position to check
     * @param ox the origin  width position in the board
     * @param oy the origin height position in the board
     * @param width the direction to move on in the row
     * @param height the direction to move on in the column
     * @param color the color of current player
     * @return the last piece found in that direction
     */
    Piece direction(int ox,int oy, int width, int height,Color color);

    void showTable(QTableWidget *table);

};

}

#endif // BOARD_H

