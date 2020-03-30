
#include <iostream>
#include <type_traits>

#include "View.h"


using namespace std;

namespace ViewSpace {

View::View(Game & game):
    game_(game),
  countPasse(0),
  countMove(0)
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
    cout << "move = " <<countMove << endl;
    cout << "passe = " << countPasse << endl;
    showBoard();
    cout << endl;
    cout << "joueur courant est : ";
    game_.getCurrentPlayer().afficheName(cout);
    string action;

    try {

        while(countMove < 2 || countPasse < 1){
            cout << "move = " <<countMove << endl;
            cout << "passe = " << countPasse << endl;

            showCommand();
            cout << "action : ";
            cin >> action;
            if(checkAction(action)){
                playAction(action,countMove,countPasse);
            }
            else{
                throw string ("command non reconnu veuillez réessayer ");
            }
        }

        countMove = 0;
        countPasse = 0;
        game_.swapPlayer();

    } catch (string const & e) {
        cout << endl;
        cout << e;
        cout << endl;
    }
}

bool View::checkAction(string action){
    return action.find("move") != string::npos || action.find("passe") != string::npos ;
}

void View::playAction(string action,int & countMove,int & countPasse){

        if(action == "move" && countMove <2){
            cout << "veuillez entrez les coordonnées d'origine ensuite de destination " << endl;

            cout << "veuillez entrez position x de depart : ";
            int ox = game_.getCurrentPlayer().play(cin);
            cout << "veuillez entrez position y de depart : ";
            int oy = game_.getCurrentPlayer().play(cin);
            cout << "veuillez entrez position x destination : ";
            int dx = game_.getCurrentPlayer().play(cin);
            cout << "veuillez entrez position y destination : ";
            int dy = game_.getCurrentPlayer().play(cin);

            game_.move(ox,oy,dx,dy);
            countMove++;
            showBoard();
        }
        else if(action =="passe" && countPasse < 1){
            cout << "veuillez entrez les coordonnées de destination " << endl;

            cout << "veuillez entrez position x de destination : ";
            int dx = game_.getCurrentPlayer().play(cin);
            cout << "veuillez entrez position y de destination : ";
            int dy = game_.getCurrentPlayer().play(cin);

            game_.passe(dx,dy);
            countPasse++;
            showBoard();
        }

}

void View::getWinner(){
    if(game_.isOver()){
        cout << "the winner is : " << game_.getWinner().getName() << endl;
    }
}

void View::update() const{

}


}

