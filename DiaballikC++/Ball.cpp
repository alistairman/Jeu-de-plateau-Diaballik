#include <iostream>
#include <ostream>
#include <functional>

#include "Ball.h"
#include "Color.h"

namespace BallSpace {

using namespace std;

Ball::Ball(Color color){
    color_ = color;
}

Color Ball::getColor(){
    //cout << color_ << endl;
    return color_;
}

}







