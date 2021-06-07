#ifndef __OBSERVED_HPP_INCLUDED__
#define __OBSERVED_HPP_INCLUDED__

#include "../model/messages/Message.hpp"
#include "../controler/Observer.hpp"

class Observed
{
    private :
        Observer m_observer;

    public :
        void setObserver(Observer &o);
        void notifyObserver(Message &m);

};

#endif
