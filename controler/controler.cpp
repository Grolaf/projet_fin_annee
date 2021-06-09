#include "../model/Dao.hpp"
#include "controler.hpp"
#include <iostream>
#include "../model/messages/MessageFile.hpp"
#include "../model/draw.hpp"
#include "../model/messages/MessagePaint.hpp"


Controler::Controler(MyFrame* frame): Observer(), m_frame(frame)
{
    m_model = new MyModel();
}

void Controler::treatMessage(Message *m)
{
    MessageFile* messageFile = nullptr;
    MessagePaint* messagePaint = nullptr;

    switch (m->getType())
    {
        case OPEN_FILE:
            messageFile = dynamic_cast<MessageFile*>(m);
            Dao::OpenFile(messageFile->getFileName());
            break;
        case SAVE_FILE:
            std::cout << "File saved" << std::endl;
            break;

        case PAINT :
            messagePaint = dynamic_cast<MessagePaint*>(m);
            paintBoard(messagePaint->getX(), messagePaint->getY(), messagePaint->getSize());
            refreshBoard();
            break;

        case REFRESH:
            refreshBoard();
            break;

        default:
            std::cout << "Test" << std::endl;
            break;
    }
}

Controler::~Controler(){
    delete m_model;
}

void Controler::paintBoard(int x, int y, int size)
{
    // Ajout d'un rectangle pour le test
    m_model->AddRect(x, y , size, size);
}

void Controler::refreshBoard()
{
    Draw* draw = m_model->GetDraw();
    m_frame->RefreshDrawing();
    m_frame->GetDrawingPanel()->Update();

    m_frame->GetDrawingPanel()->PaintRect(draw->getRectangles());
    m_frame->GetDrawingPanel()->PaintTriangle(draw->getTriangles());
    m_frame->GetDrawingPanel()->PaintCircle(draw->getCircles());
}
