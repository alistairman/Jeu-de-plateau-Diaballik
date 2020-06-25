#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

using namespace GameSpace;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 * This class represents the graphical part of the game
 */
class MainWindow : public QMainWindow, public ObserverSpace::Observer
{
    Q_OBJECT


public:
    /**
     * @brief MainWindow
     * this is the constructor of the window
     * @param parent : the parent window (null here).
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    /**
     * @brief update
     * method for updating the view of the board and the current player.
     */
    void update() override;
    /**
     * @brief addPlayers
     * method to add a player in the model and display it on the window.
     */
    void addPlayers();
    /**
     * @brief quit
     * method to exit the game and close the window.
     */
    void quit();
    /**
     * @brief setGame
     * method of setting up the game.
     * @param game : the class game of the model.
     */
    void setGame(Game & game);
    /**
     * @brief updateTable
     * method to update the visual of the board.
     */
    void updateTable();
    /**
     * @brief getCurrentPlayer
     * method to get the current player and display it.
     */
    void getCurrentPlayer();
    /**
     * @brief showWinner
     * method to find out if a player has won, and if its true display the player and finish the game.
     */
    void showWinner();
    /**
     * @brief move
     * method of moving a player and displaying that movement on the board.
     */
    void move ();
    /**
     * @brief passe
     * method of making a pass to a player and displaying it on the board.
     */
    void passe ();
    /**
     * @brief initBoard
     * method for initializing the game board by placing checkers.
     */
    void initBoard();

private slots:
    /**
     * @brief on_move_clicked
     * method of calling move function when clicking on the move button.
     */
    void on_move_clicked();
    /**
     * @brief getIndice
     * method for obtaining the index of the box that is clicked on.
     */
    void getIndice(const QModelIndex &);
    /**
     * @brief on_passe_clicked
     * method of calling throw function when clicking on the throw button.
     */
    void on_passe_clicked();
    /**
     * @brief on_cancel_clicked
     * method for resetting selections.
     */
    void on_cancel_clicked();
    /**
     * @brief on_endturn_clicked
     * method of finishing one's turn and moving on to the next player when the endturn button is pressed.
     */
    void on_endturn_clicked();
    /**
     * @brief on_actionQuitter_triggered
     * method to exit the game and close the window when the exit button in the menu is clicked.
     */
    void on_actionQuitter_triggered();
    /**
     * @brief on_actionPlaying_rules_triggered
     * method to display the rules of the game when clicking on the Playing rules button in the menu.
     */
    void on_actionPlaying_rules_triggered();

private:
    /**
     * @brief isPossibleToAdd
     * method for determining whether a player can be added or not.
     * @return : true or false.
     */
    bool isPossibleToAdd();
    Ui::MainWindow *ui;
    Game  *game_=nullptr;
    /**
     * @brief rowO
     * Attribute representing the index of the line of the starting selection.
     */
    int rowO;
    /**
     * @brief rowD
     * Attribute representing the index of the line of the destination selection.
     */
    int rowD;
    /**
     * @brief colO
     * Attribute representing the index of the column of the starting selection.
     */
    int colO;
    /**
     * @brief colD
     * Attribute representing the index of the column of the destination selection.
     */
    int colD;
    /**
     * @brief countMove
     * Attribute for counting the number of movements performed.
     */
    int countMove;
    /**
     * @brief countPasse
     * Attribute for counting the number of throw performed.
     */
    int countPasse;

};


#endif // MAINWINDOW_H
