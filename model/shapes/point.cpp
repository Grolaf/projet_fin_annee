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
}
Point::Point(int coord)
{
    m_x = coord;
    m_y = coord;
}
Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
}
Point::~Point()
{
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

void Point::write(std::ostream &file) const
{
    file.write((char*)&m_x, sizeof(m_x));
    file.write((char*)&m_y, sizeof(m_y));
}

void Point::read(std::istream &file)
{
    file.read((char*)&m_x, sizeof(m_x));
    file.read((char*)&m_y, sizeof(m_y));
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
