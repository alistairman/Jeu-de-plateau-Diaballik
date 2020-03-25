
#include <iostream>

#include "Players.h"

using namespace std;

namespace PlayersSpace {


Players::Players(string name,Color color):
    name_(name),
    color_(color)


{}

string Players::getName(){
    return name_;
}

void Players::tapeName(){
    cout << "veuillez entrez votre nom : ";
}

ostream &  Players::afficheName(ostream & c ){
    c <<  name_ << endl;
    return c;
}

unsigned Players::play(){
    int x = 0;
    cout << "veuillez entrez un entier : ";
    cin >> x;
    cout << endl;
    return x;
}


Color Players::getColor(){
    return color_;
}




}
