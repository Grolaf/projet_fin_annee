#include "controler.hpp"
#include "Observer.hpp"
#include <iostream>

Controler::Controler(): Observer()
{
}

void Controler::treatMessage(Message &m)
{
    switch (m.getType())
    {
        case OPEN_FILE:
            std::cout << "File open" << std::endl;
            break;
        case SAVE_FILE:
            std::cout << "File saved" << std::endl;
            break;

        default:

            break;
    }
}
