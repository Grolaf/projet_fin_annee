//
// Created by barriean on 09/06/2021.
//

#include "MyModel.hpp"

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
    Rectangle* r = new Rectangle(x, y, width, height, "", color, borderColor, borderSize,  filled);
    m_draw->addShape(r);
}
void MyModel::AddCircle(int x, int y, int radius, MyRGB color, MyRGB borderColor, int borderSize, bool filled)
{
    Circle* c = new Circle(x, y, radius, "", color, borderColor, borderSize, filled);
    m_draw->addShape(c);
}

/*************************************************/
/*      Methods    */

Shape* MyModel::getSelection(int x, int y) {
    return m_draw->getSelection(x, y);
}

