#include "Players.h"
#include <iostream>
#include <ostream>

namespace Players {

using namespace std;

Players::Players(std::string name){
    name_ = name;
}

std::string Players::getName(){
    cout << name_ << endl;
    return name_;
}

}
