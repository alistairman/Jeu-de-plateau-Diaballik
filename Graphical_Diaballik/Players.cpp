
#include <iostream>
#include <string>
#include <sstream>
#include "Players.h"

using namespace std;

template <typename Base, typename T>

inline bool instanceof(const T*){
    return is_base_of<Base,T>::value;
}

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

int Players::play(istream & c){
    string ret{};
    int temp{};
    c >> ret;

    if(istringstream(ret) >> temp){
        istringstream(ret) >> temp;
    }
    else{
        throw string("valeur numerique non valide! réessayez ");
    }

    return temp;
}


Color Players::getColor(){
    return color_;
}




}
