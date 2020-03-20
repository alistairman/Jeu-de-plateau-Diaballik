#include <iostream>
#include <type_traits>
#include "Game.h"
#include "Board.h"

using namespace std;
using namespace GameSpace;
using namespace BoardSpace;

ostream& operator << (ostream& os, const Color& obj)
{
   os << static_cast<std::underlying_type<Color>::type>(obj);
   return os;
}


int main()
{

    //vector <vector <int>> vect (7,vector<int>(7,0));
    Game game = Game(7,7,"ali","red");
    game.welcome();
    game.showBoard();
    game.start();


    cout << "---------------------------" << endl;
    cout << " Hello World!" << endl;
    return 0;
}
