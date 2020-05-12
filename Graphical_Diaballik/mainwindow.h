#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

using namespace GameSpace;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public ObserverSpace::Observer
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void update() override;
    void addPlayers();
    void quit();
    void setGame(Game & game);
    void updateTable();
    void getCurrentPlayer();
    void showWinner();


private slots:

    void on_move_clicked();
    void getIndice(const QModelIndex &);
    void move ();
    void passe ();
    void on_passe_clicked();
    void on_cancel_clicked();

private:
    bool isPossibleToAdd();
    Ui::MainWindow *ui;
    Game  *game_=nullptr;
    int rowO;
    int rowD;
    int colO;
    int colD;
    int countMove;
    int countPasse;

};


#endif // MAINWINDOW_H
