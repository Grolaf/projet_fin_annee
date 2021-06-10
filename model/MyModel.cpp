//
// Created by barriean on 09/06/2021.
//

#include "MyModel.hpp"

MyModel::MyModel()
{
    m_draw = new Draw();
}

Draw* MyModel::GetDraw()
{
    return m_draw;
}

void MyModel::AddRect(int x, int y , int width, int height, MyRGB color, bool filled)
{
    Rectangle* r = new Rectangle(x, y, width, height, "", color, filled);
    m_draw->addShape(r);
}
void MyModel::AddCircle(int x, int y, int radius, MyRGB color, bool filled)
{
    Circle* c = new Circle(x, y, radius, "", color, filled);
    m_draw->addShape(c);
}

