
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

int Players::play(istream & c){
    int x = 0; c >> x;
    return x;
}


Color Players::getColor(){
    return color_;
}




}
