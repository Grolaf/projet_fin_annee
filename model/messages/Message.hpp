#ifndef __MESSAGES_HPP_INCLUDED__
#define __MESSAGES_HPP_INCLUDED__

#include "MessagesTypes.hpp"

class Message
{

    private :
        MessagesTypes type;

    public : 
        void setMessageType(MessagesTypes t)
        {
            type = t;
        }
};

#endif
