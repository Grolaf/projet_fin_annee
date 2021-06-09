#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Rectangle::Rectangle(int xLeftCorner, int yLeftCorner, int width, int height, string label): m_w(width), m_h(height), m_corner(xLeftCorner, yLeftCorner), Shape(label)
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

void Rectangle::Move(int x, int y)
{
    m_corner.move(x, y);
}
bool Rectangle::isInside(Rectangle& r) const
{
    Point cornerR(r.getCorner());

    return m_corner.GetX() >= cornerR.GetX() && m_corner.GetY() >= cornerR.GetY() && m_corner.GetX() + m_w <= cornerR.GetX() + r.getWidth() && m_corner.GetY() + m_h <= cornerR.GetY() + r.getHeight();
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



