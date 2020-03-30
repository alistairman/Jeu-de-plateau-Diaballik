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
    //vector <vector <int>> vect (7,vector<int>(7,0));

    Game game = Game(7,7);
    //View view = View(game);
    //View * v = &view;
    //game.registerObserver(view);
    //view.addPlayers();
    game.start();

    while(!game.isOver()){
        //view.getAction();
    }

    //view.getWinner();

    cout << "---------------------------" << endl;
    cout << " Hello World!" << endl;
    return 0;
}
