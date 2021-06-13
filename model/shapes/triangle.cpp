#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"

using namespace std;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3, MyRGB color, MyRGB borderColor, int borderSize, bool filled): Shape(color,borderColor, borderSize,  filled), m_p1(p1), m_p2(p2), m_p3(p3)
{
}

Triangle::Triangle(): Shape(), m_p1(0, 0), m_p2(0, 0), m_p3(0, 0)
{
}


Triangle::~Triangle()
{
}
/***************************************************************************************/
/*      Getters         */

Rectangle* Triangle::getRectangleEnglobant() const
{
    Point topLeftCorner(getMinX(), getMaxY());
    int width = getMaxX() - getMinX();
    int height = getMaxY() - getMinY();

    Rectangle* r = new Rectangle(topLeftCorner.GetX(), topLeftCorner.GetY(), width, height);
    return r;
}

int Triangle::getMaxX() const
{
    return max(max(m_p1.GetX(), m_p2.GetX()), m_p3.GetX());
}
int Triangle::getMaxY() const
{
    return max(max(m_p1.GetY(), m_p2.GetY()), m_p3.GetY());
}
int Triangle::getMinX() const
{
    return min(min(m_p1.GetX(), m_p2.GetX()), m_p3.GetX());
}
int Triangle::getMinY() const
{
    return min(min(m_p1.GetY(), m_p2.GetY()), m_p3.GetY());
}

/***************************************************************************************/
/*      Methods         */

float Triangle::perimeter()const
{
    return m_p1.Distance(m_p2) + m_p2.Distance(m_p3) + m_p3.Distance(m_p1); 
}

float Triangle::surface()const
{
    float cote1 = m_p1.Distance(m_p2);
    float cote2 = m_p2.Distance(m_p3);
    float cote3 = m_p3.Distance(m_p1);
    float s = (1.0/2) * (cote1 + cote2 + cote3);
    return sqrt(s * (s - cote1) * (s - cote2) * (s - cote3));
}

void Triangle::move(int xTranslate, int yTranslate) {
    m_p1.move(xTranslate,yTranslate);
    m_p2.move(xTranslate,yTranslate);
    m_p3.move(xTranslate,yTranslate);
}

void Triangle::write(std::ostream &file) const
{
    file.write((char*)&typeID, sizeof(typeID));
    Shape::write(file);
    m_p1.write(file);
    m_p2.write(file);
    m_p3.write(file);
}
void Triangle::read(std::istream &file)
{
    // Le typeid est lu par la fonction qui aiguillera l'écriture
    Shape::read(file);
    m_p1.read(file);
    m_p2.read(file);
    m_p3.read(file);
}

/***************************************************************************************/
/*      Class Methods         */

Triangle* Triangle::buildFromFile(std::istream &file)
{
    Triangle* t = new Triangle();
    t->read(file);

    return t;
}

int Triangle::typeID = 4;