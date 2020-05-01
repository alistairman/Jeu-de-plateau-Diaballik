#include "mainwindow.h"
#include <QApplication>
#include "Game.h"


int main(int argc, char *argv[])
{

    Game *game = new Game(7,7);
    QApplication a(argc, argv);
    MainWindow w;
    w.setGame(game);
    w.show();
    w.addPlayers();
    w.initGame();
    return a.exec();
}
