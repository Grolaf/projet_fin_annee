#include "shape.hpp"
#include <iostream>

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Shape::Shape(MyRGB color,MyRGB borderColor, int borderSize, bool filled) : m_color(color), m_borderColor(borderColor), m_borderSize(borderSize), m_filled(filled)
{
}

Shape::Shape(const Shape& f) : m_color(f.m_color),m_borderColor(f.m_borderColor), m_borderSize(f.m_borderSize),  m_filled(f.m_filled)
{

}

Shape::~Shape()
{
}

/***************************************************************************************/
/*      getters        */

bool Shape::isFilled() const
{
    return m_filled;
}

/***************************************************************************************/
/*      Methods        */

void Shape::write(std::ostream &file) const
{
    m_color.write(file);
    m_borderColor.write(file);
    file.write((char*)&m_borderSize, sizeof(m_borderSize));
    file.write((char*)&m_filled, sizeof(m_filled));
}

void Shape::read(std::istream &file)
{
    m_color.read(file);
    m_borderColor.read(file);
    file.read((char*)&m_borderSize, sizeof(m_borderSize));
    file.read((char*)&m_filled, sizeof(m_filled));
}