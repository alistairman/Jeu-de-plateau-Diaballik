#include "Ball.h"
#include "Color.h"

#include <iostream>
#include <ostream>
#include <functional>



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







