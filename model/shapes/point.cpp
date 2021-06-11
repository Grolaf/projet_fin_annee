#include "point.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/***************************************************************************************************/
/**     Builders and destroyers : */

Point::Point()
{
    m_x = 0;
    m_y = 0;
    m_pointCount++;
    cout << __func__ << " utilisee pour " << this << endl;
}
Point::Point(int coord)
{
    m_x = coord;
    m_y = coord;
    m_pointCount++;
    cout << __func__ << " utilisee pour " << this << endl;
}
Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
    m_pointCount++;
    cout << __func__ << " utilisee pour " << this << endl;
}
Point::~Point()
{
    cout << __func__ << " utilisee pour " << this << endl;
    m_pointCount--;
}
void Point::Display() const
{
    cout << "( " <<  m_x  << " ; " << m_y << " ).";
}

/***************************************************************************************************/
/*      Methods     */

void Point::move(int x, int y)
{
    m_x += x;
    m_y += y;
}

bool Point::XEqualsY() const
{
    return m_x == m_y;
}

float Point::Distance(Point const& p) const
{
    return sqrt(pow(p.GetX() - this->GetX(), 2) + pow(p.GetY() - this->GetY(), 2));
}

float Point::Distance(int x, int y) const
{
    return sqrt(pow(x - this->GetX(), 2) + pow(y - this->GetY(), 2));
}

/***************************************************************************************************/
/*      Getters     */

int Point::GetX() const
{
    return m_x;
}
int Point::GetY() const
{
    return m_y;
}

/***************************************************************************************************/
/*      Setters     */

void Point::SetX(int x)
{
    m_x = x;
}
void Point::SetY(int y)
{
    m_y = y;
}

/***************************************************************************************************/
/*      Static methods     */

int Point::m_pointCount = 0;

int Point::GetPointCount()
{
    return Point::m_pointCount;
}
