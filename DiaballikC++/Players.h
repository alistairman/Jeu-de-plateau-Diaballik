#ifndef PLAYERS_H
#define PLAYERS_H

#include<string>

#include "Color.h"

using namespace std;

namespace PlayersSpace {

    class Players{
    private:
        string name_;
        Color color_;
    public:

        Players(string name, Color color);
        string getName();
        ostream & afficheName(ostream & c);
        int play();
        void tapeName();
        Color getColor();
    };

}

#endif // PLAYERS_H
