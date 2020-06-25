#include <iostream>
#include "Game.h"
#include "View.h"

using namespace std;
using namespace GameSpace;
using namespace ViewSpace;


int main()
{
    Game game = Game(7,7);
    // rnvs : changer taille (7, 7) pour observer les bogues !
    View view = View(game);

    view.addPlayers();
    game.start();

    while (!game.isOver())
    {
        view.getAction();
    }

    view.getWinner();
    return 0;
}
