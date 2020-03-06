#ifndef PLAYERS_H
#define PLAYERS_H

#include "Ball.h"

namespace PlayersSpace {

    class Players{
    private:
        std::string name_;
        Color color_;
    public:
            Players(std::string color);
            std::string getName();
            void play(unsigned x, unsigned y); // a definir encore
    };

}

#endif // PLAYERS_H
