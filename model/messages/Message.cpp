#include "Message.hpp"
#include "MessagesTypes.hpp"

Message::Message(MessagesTypes t) : m_type(t)
{}

void Message::setMessageType(MessagesTypes t)
{
    m_type = t;
}

MessagesTypes Message::getType()
{
    return m_type;
}
