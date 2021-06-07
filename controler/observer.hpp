#ifdef __OBSERVER_HPP_INDLUDED__
#define __OBSERVER_HPP_INDLUDED__

#include "../view/observed.hpp"

virtual class Observer
{
    public :
        Observed observed;
        void setObserved(Observed o)
        {
            observe = o;
        }
        virtual void treatMessage(Message &m);
};

#endif
