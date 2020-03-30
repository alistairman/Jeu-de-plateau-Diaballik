#include <iostream>
#include <type_traits>
#include "Game.h"
#include "View.h"


using namespace std;
using namespace GameSpace;
using namespace ViewSpace;


ostream& operator << (ostream& os, const Color& obj)
{
   os << static_cast<std::underlying_type<Color>::type>(obj);
   return os;
}


int main()
{
    Game game = Game(7,7);
    View view = View(game);
    //View * v = &view;
    //game.registerObserver((Observer)view);
    view.addPlayers();
    game.start();

    while(!game.isOver()){
        view.getAction();
    }

    view.getWinner();

    cout << "---------------------------" << endl;
    cout << " Hello World!" << endl;
    return 0;
}
