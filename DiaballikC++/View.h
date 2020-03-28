#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Observer.h"
#include "Game.h"

namespace ViewSpace {

using namespace ObserverSpace;
using namespace GameSpace;

class View {
private:
    Game & game_;

public:
    View(Game & game);
    void welcome();
    void addPlayers();

};

}



#endif // VIEW_H
