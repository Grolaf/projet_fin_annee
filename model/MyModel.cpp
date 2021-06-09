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

void MyModel::AddRect(int x, int y , int width, int height)
{
    Rectangle r(x, y, width, height, "");
    m_draw->addRectangle(r);
}

