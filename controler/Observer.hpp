#ifndef __OBSERVER_HPP_INCLUDED__
#define __OBSERVER_HPP_INCLUDED__

#include "../model/messages/Message.hpp"

class Observer
{
    public :
        Observer();
        virtual void treatMessage(Message *m);
        ~Observer() = default;
};

#endif
