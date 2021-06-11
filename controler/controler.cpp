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

        case PAINT_RECT :
            messagePaint = dynamic_cast<MessagePaint*>(m);
            AddRect(messagePaint->getX(), messagePaint->getY(), messagePaint->getWidth(), messagePaint->getHeight(),
                    messagePaint->getShapeColor(), messagePaint->getBorderColor(), messagePaint->getBorderSize(), messagePaint->getFilled());
            refreshBoard();
            break;

        case PAINT_CIRCLE :
            messagePaint = dynamic_cast<MessagePaint*>(m);
            AddCircle(messagePaint->getX(), messagePaint->getY(), messagePaint->getRadius(),
                      messagePaint->getShapeColor(), messagePaint->getBorderColor(), messagePaint->getBorderSize(),  messagePaint->getFilled());
            refreshBoard();
            break;

        case REFRESH:
            refreshBoard();
            break;

        case PREVISUALIZE:
            switchPrevisualize();
            break;

        case SELECTION:
            switchSelection();
            break;

        case SELECT:
            messagePaint = dynamic_cast<MessagePaint*>(m);
            selectShape(messagePaint->getX(), messagePaint->getY());
            break;

        default:
            std::cout << "Test" << std::endl;
            break;
    }
}

Controler::~Controler(){
    delete m_model;
}

/*************************************************/
/*      setters    */

void Controler::AddRect(int x, int y, int width, int height, MyRGB color,MyRGB borderColor, int borderSize,  bool filled)
{
    // Ajout d'un rectangle pour le test
    m_model->AddRect(x, y , width, height, color, borderColor, borderSize,  filled);
}

void Controler::AddCircle(int x, int y, int radius, MyRGB color, MyRGB borderColor, int borderSize, bool filled)
{
    // Ajout d'un rectangle pour le test
    m_model->AddCircle(x, y , radius, color, borderColor, borderSize, filled);
}

/*************************************************/
/*      Usual Methods    */

void Controler::refreshBoard()
{
    Draw* draw = m_model->GetDraw();
    m_frame->GetDrawingPanel()->Refresh();
    m_frame->GetDrawingPanel()->Update();

    m_frame->GetDrawingPanel()->PaintShapes(draw->getShapes());
    m_frame->GetDrawingPanel()->Previsualize();
}

void Controler::switchPrevisualize() {
    m_frame->GetDrawingPanel()->switchPevisualize();
    refreshBoard();
}
void Controler::switchSelection() {
    m_frame->GetDrawingPanel()->switchSelection();
    refreshBoard();
}

void Controler::selectShape(int x, int y)
{
    Shape* shape = m_model->getSelection(x, y);

    if(shape != nullptr)
    {

    }
}
