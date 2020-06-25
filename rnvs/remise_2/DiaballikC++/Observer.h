#ifndef OBSERVER_H
#define OBSERVER_H

namespace ObserverSpace {

class Observable;

/**
 * @brief The Observer class
 * this class represent the observer of the game
 */
class Observer{

public:
    //this method is the destructor of observer class
    virtual ~Observer() = default;

    //this method is called when a change happend in the observable class
    virtual void update() const = 0;

protected:

    //this method is the constructor of the obsever class
    Observer() = default;
};

}

#endif // OBSERVER_H
