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
    explicit MainWindow(QWidget *parent = nullptr,Game * game = 0);
    ~MainWindow() override;
    void update() const override;
    void addPlayers();
    void quit();
    void setGame(Game * game);
    void initGame();

private slots:

private:
    bool isPossibleToAdd();
    Ui::MainWindow *ui;
    Game  * game_;

};


#endif // MAINWINDOW_H
