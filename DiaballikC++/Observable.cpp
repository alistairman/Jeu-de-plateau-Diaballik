
#include "Observable.h"
#include "Observer.h"


namespace ObservableSpace {


void Observable::registerObserver(Observer * observer)
{
    observers_.insert(observer);
}


void Observable::notifyObservers() const
{
    for (Observer * observer : observers_)
    {
        //observer -> update(this);
    }
}


}
