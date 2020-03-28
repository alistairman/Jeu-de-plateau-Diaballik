#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include<set>
//#include "View.cpp"

namespace ObservableSpace {

class Observer;

class Observable{


public:
    virtual void registerObserver(Observer * observer) final;
    virtual ~Observable() = default;

protected:
    std::set<Observer *> observers_ { };
    Observable()=default;
    virtual void notifyObservers() const final;


};

}


#endif // OBSERVABLE_H
