#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "circle.hpp"

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Circle::Circle(int x, int y, int radius, MyRGB color, MyRGB borderColor, int borderSize,  bool filled): Shape(color, borderColor, borderSize, filled), m_center(x, y), m_radius(radius)
{
}

Circle::Circle(): Shape(), m_center()
{
    m_radius = 0;
}
Circle::~Circle()
{
}

/***************************************************************************************/
/*      Usual Methods        */


float Circle::perimeter()const
{
    return 2 * M_PI * m_radius;
}

float Circle::surface()const
{
    return M_PI * pow(m_radius, 2);
}

/***************************************************************************************/
/*      Getters        */

Point Circle::getCenter() const
{
    return m_center;
}

int Circle::getRadius() const {
    return m_radius;
}

Rectangle* Circle::getRectangleEnglobant() const {

    Rectangle* r = new Rectangle(m_center.GetX() - m_radius, m_center.GetY() - m_radius, m_radius *  2 , m_radius * 2);

    return r;
}

/***************************************************************************************/
/*      Setters        */

void Circle::setCenter(int x, int y)
{
    m_center.SetX(x);
    m_center.SetY(y);
}

void Circle::setRadius(int r) {
    m_radius = r;
}

/***************************************************************************************/
/*      Methods        */

void Circle::move(int xTranslate, int yTranslate) {
    m_center.move(xTranslate, yTranslate);
}

void Circle::write(std::ostream &file) const
{
    file.write((char*)&typeID, sizeof(typeID));
    Shape::write(file);
    m_center.write(file);
    file.write((char*)&m_radius, sizeof (m_radius));
}
void Circle::read(std::istream &file)
{
    // Le typeid est lu par la fonction qui aiguillera l'écriture
    Shape::read(file);
    m_center.read(file);
    file.read((char*)&m_radius, sizeof (m_radius));
}

/***************************************************************************************/
/*      Class Methods        */

Circle* Circle::buildFromFile(std::istream &file)
{
    Circle* c = new Circle();
    c->read(file);

    return c;
}

int Circle::typeID = 3;
