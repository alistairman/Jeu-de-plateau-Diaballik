#ifndef PLAYERS_H
#define PLAYERS_H

#include "Ball.h"

namespace Players {

    class Players{
    private:
        std::string name_;
        Color color_;
    public:
            Players(std::string color);
            std::string getName();
    };

}

#endif // PLAYERS_H
