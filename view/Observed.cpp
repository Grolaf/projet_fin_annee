#include "Observed.hpp"

void Observed::setObserver(Observer *o)
{
    m_observer = o;
}

void Observed::notifyObserver(Message *m)
{
    m_observer->treatMessage(m);
}

Observed::~Observed(){}
