#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include "Observer.h"

using namespace std;
using namespace ObserverSpace;

namespace ObservableSpace {

//class Observer;

/**
 * @brief The Observable class
 * this class represent observable class of the game
 */
class Observable{

public:
    //this method is the constructor of the observable class
    Observable()=default;

    //this method is a desctrutor of the observable class
    virtual ~Observable() = default;

    //this method registrer a new observer
    virtual void registerObserver(Observer  * observer) = 0;

    // this method delete an observer from the list of observers
    virtual void unregisterObserver(Observer * observer) = 0 ;

    //this method notify all observer registered
    virtual void notifyObservers() = 0;

protected:
    // this attribute is a list of all observer registered
    set<Observer *> observers_ { };


};

}

#endif // OBSERVABLE_H
