
#include <iostream>
#include <type_traits>

#include "View.h"


using namespace std;

namespace ViewSpace {

View::View(Game & game):
    game_(game)
{}


void View::addPlayers(){
    //game_.registerObserver(this);
    cout << endl;
    cout << " ==========================" << endl;
    cout << "  Bienvenus Dans DIABALLIK " << endl;
    cout << " ==========================" << endl;
    cout << endl;

    while(game_.isPossibleToAdd()){
        string name;
        cout << "veuillez entrez le nom d'un jouer : ";
        cin >> name;
        game_.addPlayer(name);
    }
}

void View::showBoard(){
    game_.showBoard(cout);
}


void View::showCommand(){
    cout << endl;
    cout << " taper les commandes : " << endl;
    cout << " passe = pour passer la ball " << endl;
    cout << " move  = pour deplacer un pion " << endl;
    cout << endl;
}

void View::getAction(){

    cout << "joueur courant est : ";
    game_.getCurrentPlayer().afficheName(cout);
    string action;
    int countPasse = 0;
    int countMove = 0;
    while (countMove <2 && countPasse <1) {
        showCommand();
        cout << "action : ";
        cin >> action;
        if(checkAction(action)){
            playAction(action,countMove,countPasse);
        }
        else{
            cout << "commande non reconnu, essayer de nouveau " << endl;
        }
    }
    countMove = 0;
    countPasse = 0;
    game_.swapPlayer();

}

bool View::checkAction(string action){
    return action.find("move") != string::npos || action.find("passe") != string::npos ;
}

void View::playAction(string action,int & countMove,int & countPasse){

    if(action == "move" && countMove <2){
        cout << "veuillez entrez les coordonnées d'origine ensuite de destination " << endl;
        int ox = game_.getCurrentPlayer().play();
        int oy = game_.getCurrentPlayer().play();
        int dx = game_.getCurrentPlayer().play();
        int dy = game_.getCurrentPlayer().play();
        game_.move(ox,oy,dx,dy);
        countMove++;
    }
    else{

    }

    if(action =="passe" && countPasse < 1){
        cout << "veuillez entrez les coordonnées de destination " << endl;
        int dx = game_.getCurrentPlayer().play();
        int dy = game_.getCurrentPlayer().play();
        game_.passe(dx,dy);
        countPasse++;
    }else{

    }
}

void View::getWinner(){
    if(game_.isOver()){
        cout << "the winner is : " << game_.getWinner().getName() << endl;
    }
}

void View::update() const{
    cout << endl;
    cout << "Board : " << endl;

    cout << endl;
}


}

