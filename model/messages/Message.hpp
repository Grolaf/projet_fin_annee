#ifndef __MESSAGES_HPP_INCLUDED__
#define __MESSAGES_HPP_INCLUDED__


#include "MessagesTypes.hpp"

class Message
{
    protected :
        MessagesTypes m_type;

    public : 
        Message(const MessagesTypes t);
        virtual ~Message();

        // Getters
        MessagesTypes getType() const;

        // Setters
        void setMessageType(const MessagesTypes t);
};

#endif
