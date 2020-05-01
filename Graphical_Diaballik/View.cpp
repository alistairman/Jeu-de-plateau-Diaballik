
#include <iostream>
#include <type_traits>
#include "View.h"
#include "Players.h"


using namespace std;
using namespace PlayersSpace;


namespace ViewSpace {

View::View(Game & game):
    game_(game),
    countPasse{0},
    countMove{0}
{}

View::~View(){
    game_.unregisterObserver(this);
    game_.~Game();
}

void View::addPlayers(){
    game_.registerObserver(this);
    cout << endl;
    cout << " ==========================" << endl;
    cout << "  Bienvenus Dans DIABALLIK " << endl;
    cout << " ==========================" << endl;
    cout << endl;

    list<Players> players;
    while(players.size()<2){

        cout << "veuillez entrez le nom d'un jouer : ";
        string name = "";
        cin >> name;
        Players * p  = new Players(name,Color::NO);
        players.push_back(*p);
        //free(p);
    }
    game_.addPlayers(players);
}




void View::showCommand(){
    cout << endl;
    cout << " taper les commandes : " << endl;
    cout << " passe = pour passer la ball " << endl;
    cout << " move  = pour deplacer un pion " << endl;
    cout << endl;
}

void View::getAction(){
    cout << endl;
    cout << "joueur courant est : ";
    game_.getCurrentPlayer().afficheName(cout);
    string action;

    try {

        while (countMove<2 || countPasse < 1){
            cout << endl;
            cout << countMove <<" move done"<< endl;
            cout << countPasse << " passe done " << endl;

            showCommand();
            cout << "action : ";
            cin >> action;
            if(checkAction(action)){
                playAction(action,countMove,countPasse);
            }
            else{
                throw string ("command non reconnu! veuillez réessayer ");
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

        }
        else if(action =="passe" && countPasse < 1){
            cout << "veuillez entrez les coordonnées de destination " << endl;

            cout << "veuillez entrez position x de destination : ";
            int dx = game_.getCurrentPlayer().play(cin);
            cout << "veuillez entrez position y de destination : ";
            int dy = game_.getCurrentPlayer().play(cin);

            game_.passe(dx,dy);
            countPasse++;
        }
        else{
            throw string(" action déjà réalisé veuillez réessayer ");
        }
}

void View::getWinner(){
    if(game_.isOver()){
        cout << "the winner is : ";
        game_.getWinner().afficheName(cout);
        cout << endl;
        this->~View();
    }
}

void View::update() const{
    game_.showBoard(cout);
}


}

