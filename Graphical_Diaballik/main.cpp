#include "mainwindow.h"
#include <QApplication>
#include "Game.h"
#include "View.h"

#include <iostream>

using namespace std;
using namespace ViewSpace;
using namespace GameSpace;

int main(int argc, char *argv[])
{

    Game game =Game(7,7);
    View view = View(game);
    QApplication a(argc, argv);
    MainWindow w;
    w.setGame(game);
    w.show();
    w.addPlayers();
    game.start();

    return a.exec();
}

