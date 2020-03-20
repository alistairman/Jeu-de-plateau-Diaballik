
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

ostream &  Players::afficheName(ostream & c ){
    c <<  name_ << endl;
    return c;
}

int Players::play(){
    int x = 0;
    cin >> x;
    return x;
}

}
