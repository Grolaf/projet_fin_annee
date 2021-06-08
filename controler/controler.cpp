#include "../model/Dao.hpp"
#include "controler.hpp"
#include "Observer.hpp"
#include <iostream>
#include "../model/messages/MessageFile.hpp"

Controler::Controler(): Observer()
{
}

void Controler::treatMessage(Message *m)
{
    std::cout << "Controleur" << std::endl;
    MessageFile* message = nullptr;

    switch (m->getType())
    {
        case OPEN_FILE:
            message = dynamic_cast<MessageFile*>(m);
            Dao::OpenFile(message->getFileName());
            break;
        case SAVE_FILE:
            std::cout << "File saved" << std::endl;
            break;

        default:
            std::cout << "Test" << std::endl;
            break;
    }
}

Controler::~Controler(){}
