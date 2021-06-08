#include "Message.hpp"
#include "MessagesTypes.hpp"

Message::Message(const MessagesTypes t) : m_type(t)
{
}

void Message::setMessageType(const MessagesTypes t)
{
    m_type = t;
}

MessagesTypes Message::getType()const
{
    return m_type;
}


Message::~Message(){}
