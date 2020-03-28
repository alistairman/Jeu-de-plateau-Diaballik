
#include <iostream>
#include <type_traits>

#include "View.h"


using namespace std;
//using namespace GameSpace;
using namespace BoardSpace;


namespace ViewSpace {


View::View(Game & game):
    game_ (game)
{}


void welcome(){
    cout << " =======================" << endl;
    cout << " Bienvenu Dans DIABALLIK " << endl;
    cout << " =======================" << endl;
    cout << endl;
}

void View::addPlayers(){
    while(game_.isPossibleToAdd()){
        string name;
        cout << "veuillez entrez le nom du jouer : ";
        cin >> name;
        game_.addPlayer(name);
    }
}

void View::showBoard(){
    game_.showBoard();
}

void View::getAction(string action){
    if(action.find("move")){
        //game_.move();
    }
    if(action.find("passe")){

    }
}


}

