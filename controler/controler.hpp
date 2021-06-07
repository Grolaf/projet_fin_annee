#ifndef __CONTROLER_HPP_INCLUDED__
#define __CONTROLER_HPP_INCLUDED__

#include "Observer.hpp"
#include "../model/messages/Message.hpp"

class Controler: public Observer
{
    public :
        Controler();
        void treatMessage(Message &m);
};

#endif
