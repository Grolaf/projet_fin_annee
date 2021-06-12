#include <iostream>
#include "rectangle.hpp"

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Rectangle::Rectangle(int xLeftCorner, int yLeftCorner, int width, int height, string label, MyRGB color, MyRGB borderColor, int borderSize, bool filled): m_w(width), m_h(height), m_corner(xLeftCorner, yLeftCorner), Shape(label, color, borderColor, borderSize, filled)
{
    m_rectCount++;
}
 
Rectangle::Rectangle(Point& p, int width, int height): m_w(width), m_h(height), m_corner(p), Shape()
{
    m_rectCount++;
}


Rectangle::~Rectangle()
{
    m_rectCount--;
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

void Rectangle::display() const
{
    Shape::display();
    cout << "  Corner = ";
    m_corner.Display();
    cout << ". w = " << m_w << " , h = " << m_h;
}

float Rectangle::surface()const
{
    return m_h * m_w;
}

float Rectangle::perimeter()const
{
    return (m_h + m_w) * 2;
}


/***************************************************************************************/
/*      classMethods        */

int Rectangle::m_rectCount = 0;

int Rectangle::GetRectCount()
{
    return m_rectCount;
}



