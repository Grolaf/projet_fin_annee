#ifdef __OBSERVED_HPP_INCLUDED__
#define __OBSERVED_HPP_INCLUDED__

#include "../controler/observer.hpp"

virtual class Observed
{
    private : 
        Observer observer;

    public : 
        void addObserver(Observer o)
        {
            observer = o;
        }

        void notifiyObserver(Message &m);
        {
            observer.treatMessage(m);
        }
};

#endif
