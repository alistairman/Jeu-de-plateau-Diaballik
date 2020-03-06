#include "Ball.h"
#include "Color.h"

#include <iostream>
#include <ostream>
#include <functional>

using namespace std;

namespace BallSpace {



Ball::Ball(Color color){
    color_ = color;
}

Ball::Ball(){
    color_ = Color::NO;
}

Color Ball::getColor(){
    //cout << color_ << endl;
    return color_;
}

}







