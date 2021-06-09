#include "shape.hpp"
#include <iostream>

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Shape::Shape(string label, MyRGB color, bool filled) :m_label(label), m_color(color), m_filled(filled)
{
}

Shape::Shape()
{
    m_label = "";
    m_filled = false;
}

Shape::Shape(const Shape& f) : m_label(f.m_label), m_color(f.m_color), m_filled(f.m_filled)
{

}

Shape& Shape::operator=(const Shape &f)
{
    SetLabel(f.GetLabel());
    m_filled = f.m_filled;
    m_color = f.m_color;
    return (*this);
}

Shape::~Shape()
{
}

/***************************************************************************************/
/*      getters        */

string Shape::GetLabel() const
{
    return m_label;
}

MyRGB Shape::GetColor() const {
    return m_color;
}

bool Shape::isFilled() const
{
    return m_filled;
}

/***************************************************************************************/
/*      setters        */

void Shape::SetLabel(const string str)
{
    m_label = str;
}

void Shape::SetColor(int r, int g, int b) {
    m_color.red = r;
    m_color.green = g;
    m_color.blue = b;
}

/***************************************************************************************/
/*      methods        */

void Shape::display()const
{
    cout << "Shape " << m_label << endl;
}
