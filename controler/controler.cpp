#include "../model/Dao.hpp"
#include "controler.hpp"
#include <iostream>
#include "../model/messages/MessageFile.hpp"
#include "../model/draw.hpp"
#include "../model/messages/MessagePaint.hpp"
#include "../model/messages/MessageShape.h"


Controler::Controler(MyFrame* frame): Observer(), m_frame(frame)
{
    m_model = new MyModel();

    // Setting du Draw dans la vue
    m_frame->GetDrawingPanel()->setDraw(m_model->GetDraw());
}

void Controler::treatMessage(Message *m)
{
    MessageFile* messageFile = nullptr;
    MessagePaint* messagePaint = nullptr;
    MessageShape* messageShape = nullptr;

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
            refreshBoard();
            break;

        case SELECTION:
            switchSelection();
            refreshBoard();
            break;

        case SELECT:
            messagePaint = dynamic_cast<MessagePaint*>(m);
            selectShape(messagePaint->getX(), messagePaint->getY());
            refreshBoard();
            break;

        case DELETE_SHAPE:
            messageShape = dynamic_cast<MessageShape*>(m);
            deleteShape(messageShape->getShape());
            refreshBoard();
            break;

        case COPY_SHAPE :
            messageShape = dynamic_cast<MessageShape*>(m);
            copyShape(messageShape->getShape());
            refreshBoard();
            break;

        case PASTE_SHAPE:
            pasteShape();
            refreshBoard();
            break;

        case UNDO:
            undo();
            refreshBoard();
            break;

        case REDO:
            redo();
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
    m_frame->GetDrawingPanel()->Refresh();
}

void Controler::switchPrevisualize() {
    m_frame->GetDrawingPanel()->switchPevisualize();
}
void Controler::switchSelection() {
    m_frame->GetDrawingPanel()->switchSelection();
}

void Controler::selectShape(int x, int y)
{
    Shape* shape = m_model->getSelection(x, y);

    if(shape != nullptr)
    {
        m_frame->GetDrawingPanel()->setSelectedShape(shape);
    } else
    {
        m_frame->GetDrawingPanel()->setSelectedShape(nullptr);
    }
}

void Controler::deleteShape(Shape *shape)
{
    m_model->deleteShape(shape);
    m_frame->GetDrawingPanel()->setSelectedShape(nullptr);
}
void Controler::copyShape(Shape *shape)
{
    m_model->setCopiedShape(shape);
}
void Controler::pasteShape()
{
    m_model->pasteCopiedShape();
}
void Controler::undo()
{
    m_model->undo();
}
void Controler::redo()
{
    m_model->redo();
}
