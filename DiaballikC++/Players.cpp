#include "Players.h"
#include <iostream>
#include <ostream>

using namespace std;

namespace Players {


Players::Players(std::string name){
    name_ = name;
}

std::string Players::getName(){
    cout << name_ << endl;
    return name_;
}

}
