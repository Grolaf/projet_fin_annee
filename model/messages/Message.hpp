#ifndef __MESSAGES_HPP_INCLUDED__
#define __MESSAGES_HPP_INCLUDED__

#include "MessagesTypes.hpp"

class Message
{
    protected :
        MessagesTypes m_type;

    public : 
        Message(MessagesTypes t);
        virtual ~Message() = default;
        
        void setMessageType(MessagesTypes t);
        MessagesTypes getType();
};

#endif
