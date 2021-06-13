//
// Created by barriean on 09/06/2021.
//

#include "MyModel.hpp"
#include "Dao.hpp"

MyModel::MyModel()
{
    m_draw = new Draw();
}

/*************************************************/
/*      getters    */

Draw* MyModel::GetDraw()
{
    return m_draw;
}

/*************************************************/
/*      setters    */

void MyModel::AddRect(int x, int y , int width, int height, MyRGB color, MyRGB borderColor, int borderSize, bool filled)
{
    Rectangle* r = new Rectangle(x, y, width, height, color, borderColor, borderSize,  filled);
    m_draw->addShape(r);
}
void MyModel::AddCircle(int x, int y, int radius, MyRGB color, MyRGB borderColor, int borderSize, bool filled)
{
    Circle* c = new Circle(x, y, radius, color, borderColor, borderSize, filled);
    m_draw->addShape(c);
}

/*************************************************/
/*      Methods    */

void MyModel::loadFile(std::string fileName)
{
    Dao::LoadFile(fileName.c_str(), m_draw);
}

void MyModel::saveFile(std::string fileName)
{
    Dao::SaveFile(fileName.c_str(), m_draw);
}

Shape* MyModel::getSelection(int x, int y) {
    return m_draw->getSelection(x, y);
}

void MyModel::deleteShape(Shape *shape)
{
    if(shape != nullptr)
    {
        m_draw->deleteShape(shape);
        delete shape;
    }
}

void MyModel::pasteCopiedShape()
{
    Rectangle* r;
    Triangle* t;
    Circle* c;

    if(m_copiedShape->isRectangle())
    {
        r = dynamic_cast<Rectangle*>(m_copiedShape);
        Rectangle* toPaste = new Rectangle(r->getCorner().GetX(), r->getCorner().GetY(), r->getWidth(), r->getHeight(), r->GetColor(), r->GetBorderColor(), r->GetBorderSize(), r->isFilled());
        m_draw->addShape(toPaste);
    }
    else if(m_copiedShape->isCircle())
    {
        c = dynamic_cast<Circle*>(m_copiedShape);
        Circle* toPaste = new Circle(c->getCenter().GetX(),c->getCenter().GetY(),c->getRadius(), c->GetColor(), c->GetBorderColor(), c->GetBorderSize(), c->isFilled());
        m_draw->addShape(toPaste);
    }

}

void MyModel::undo()
{
    Shape* undo = m_draw->deleteLastShape();

    if(undo != nullptr)
        m_undoRedoStack.push_back(undo);
}

void MyModel::redo()
{
    if(m_undoRedoStack.size() != 0) {
        m_draw->addShape(m_undoRedoStack.back());
        m_undoRedoStack.pop_back();
    }
}