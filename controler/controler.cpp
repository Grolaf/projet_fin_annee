#include "../model/Dao.hpp"
#include "controler.hpp"
#include <iostream>
#include "../model/messages/MessageFile.hpp"
#include "../model/shapes/draw.hpp"


Controler::Controler(MyFrame* frame): Observer(), m_frame(frame)
{
    m_model = new MyModel();
}

void Controler::treatMessage(Message *m)
{
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

        case PAINT :
              paintBoard();
            break;

        default:
            std::cout << "Test" << std::endl;
            break;
    }
}

Controler::~Controler(){
    delete m_model;
}

void Controler::paintBoard()
{
    Draw* draw = m_model->GetDraw();
    m_frame->GetDrawingPanel()->Update();

    // Ajout d'un rectangle pour le test
    m_model->AddRect();
    m_frame->GetDrawingPanel()->PaintRect(draw->getRectangles());
}
