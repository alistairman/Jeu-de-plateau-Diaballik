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

    cout << endl;
    cout << "veuillez entrez le nom du player 1 : ";
    string player1;
    cin >> player1;
    cout << "veuillez entrez le nom du player 2 : ";
    string player2;
    cin >> player2;
    cout << endl;
    Game game = Game(7,7,player1,player2);
    game.welcome();
    game.start();

    while(!game.isOver()){
        cout << endl;
        cout << "c'est à " << game.getCurrentPlayer().getName() << " de jouer " << endl;
        cout << endl;
        cout << " ==== entrez les coordonnées d'origine ==== "<< endl;
        cout << endl;

        unsigned ox = game.getCurrentPlayer().play();
        unsigned oy = game.getCurrentPlayer().play();
        cout << " ==== entrez les coordonnées de destination ==== :" << endl;
        unsigned dx = game.getCurrentPlayer().play();
        unsigned dy = game.getCurrentPlayer().play();
        game.play(ox,oy,dx,dy);
        game.swapPlayer();
    }

    if(game.isOver()){
        game.getWinner();
    }


    cout << "---------------------------" << endl;
    cout << " Hello World!" << endl;
    return 0;
}
