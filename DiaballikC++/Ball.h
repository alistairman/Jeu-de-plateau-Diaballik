#ifndef DEF_BALL
#define DEF_BALL

#include <iostream>
#include <ostream>

#include "Color.h"

namespace BallSpace {

class Ball{

    private:
        Color color_;

    public:
        Ball(Color color);
        //Ball();
        Color getColor();
};

}


#endif // HEADERS_H
