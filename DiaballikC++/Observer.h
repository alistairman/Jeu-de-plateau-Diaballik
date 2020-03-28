#ifndef OBSERVER_H
#define OBSERVER_H

//#include "Game.h"

namespace ObserverSpace {

//using namespace GameSpace;

class Observable;

class Observer{

public:
    virtual void update(const Observable * game) = 0;
    virtual ~Observer() = default;

protected:
    Observer() = default;

};


}

#endif // OBSERVER_H
