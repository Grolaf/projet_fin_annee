#include <iostream>
#include "rectangle.hpp"

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Rectangle::Rectangle(int xLeftCorner, int yLeftCorner, int width, int height, MyRGB color, MyRGB borderColor, int borderSize, bool filled): m_w(width), m_h(height), m_corner(xLeftCorner, yLeftCorner), Shape(color, borderColor, borderSize, filled)
{
}
 
Rectangle::Rectangle(Point& p, int width, int height): m_w(width), m_h(height), m_corner(p), Shape()
{
}

Rectangle::Rectangle() : Shape()
{

}


Rectangle::~Rectangle()
{
}

/***************************************************************************************/
/*      getters        */

int Rectangle::getWidth() const
{
    return m_w;
}
int Rectangle::getHeight() const
{
    return m_h;
}
int* Rectangle::getDimensions() const
{
    int *tab = new int[2];
    tab[0] = getWidth();
    tab[1] = getHeight();

    return tab;
}

Point& Rectangle::getCorner()
{
    return m_corner;
}

Rectangle* Rectangle::getRectangleEnglobant() const {

    Rectangle* r = new Rectangle(m_corner.GetX(), m_corner.GetY(), m_w, m_h);

    return r;
}


bool Rectangle::isInside(int x, int y) const
{
    Point topLeft(m_corner);
    Point bottomRight(m_corner.GetX() + m_w, m_corner.GetY() + m_h);

    return topLeft.GetX() <= x && bottomRight.GetX() >= x && topLeft.GetY() <= y && bottomRight.GetY() >= y;
}


/***************************************************************************************/
/*      setters        */

void Rectangle::setDimensions(int width, int height)
{
    m_w = width;
    m_h = height;
}
void Rectangle::setCorner(int xLeftCorner, int yLeftCorner)
{
    Point p(xLeftCorner, yLeftCorner);

    m_corner = p;
}
void Rectangle::setCorner(Point& p)
{
    m_corner = p;
}

/***************************************************************************************/
/*      Usuals methods        */

void Rectangle::move(int xTranslate, int yTranslate)
{
    m_corner.move(xTranslate, yTranslate);
}

int Rectangle::Surface() const
{
    return m_w * m_h;
}


float Rectangle::surface()const
{
    return m_h * m_w;
}

float Rectangle::perimeter()const
{
    return (m_h + m_w) * 2;
}
void Rectangle::write(std::ostream &file) const
{
    file.write((char*)&typeID, sizeof(typeID));
    Shape::write(file);
    m_corner.write(file);
    file.write((char*)&m_w, sizeof(m_w));
    file.write((char*)&m_h, sizeof(m_h));
}
void Rectangle::read(std::istream &file)
{
    // Le typeid est lu par la fonction qui aiguillera l'écriture
    Shape::read(file);
    m_corner.read(file);
    file.read((char*)&m_w, sizeof(m_w));
    file.read((char*)&m_h, sizeof(m_h));
}

/***************************************************************************************/
/*      classMethods        */

Rectangle* Rectangle::buildFromFile(std::istream &file)
{
    Rectangle *r = new Rectangle();
    r->read(file);

    return r;
}


int Rectangle::typeID = 2;



