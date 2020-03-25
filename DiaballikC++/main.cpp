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

    unsigned countPasse = 0;
    unsigned countMove = 0;

    while(!game.isOver()){


        cout << "c'est à " << game.getCurrentPlayer().getName() << " de jouer " << endl;
        cout << endl;

        string action = "";

        while(countPasse<1 || countMove<2){
            cout << endl;
            cout << " taper les commandes : " << endl;
            cout << " passe = pour passer la ball " << endl;
            cout << " move  = pour deplacer un pion " << endl;
            cout << endl;
            cin >> action;

            if(action == "passe" && countPasse<1){
                cout << " ==== entrez les coordonnées de destination ==== " << endl;
                game.action(action);
                countPasse++;
                game.showBoard();
            }

            if(action=="move" && countMove<2){
                cout << " ==== entrez les coordonnées d'origine ==== "<< endl;
                cout << endl;
                cout << " ==== entrez les coordonnées de destination ==== :" << endl;
                cout << endl;
                game.action(action);
                countMove++;
                game.showBoard();
            }

        }


        countPasse = 0;
        countMove = 0;
        game.swapPlayer();
    }

    if(game.isOver()){
        game.getWinner();
    }


    cout << "---------------------------" << endl;
    cout << " Hello World!" << endl;
    return 0;
}
