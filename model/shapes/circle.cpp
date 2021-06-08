#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "circle.hpp"

using namespace std;

Circle::Circle(int x, int y, int radius, string label): Shape(label), m_center(x, y), m_radius(radius)
{
}

Circle::Circle(): Shape(), m_center()
{
    m_radius = 0;
}
Circle::Circle(const Circle& c): Shape(c.GetLabel()), m_center(c.m_center), m_radius(c.m_radius)
{
}

Circle::~Circle()
{
}


Circle& Circle::operator=(const Circle& c)
{
    if(m_label != nullptr)
    {
        delete m_label;
    }

    m_label = new string(c.GetLabel());
    m_center = c.m_center;
    m_radius = c.m_radius;

    return (*this);
}

void Circle::display()const
{
    cout << "Circle " << *m_label << " : ";
    m_center.Display();
    cout << " radius = " << m_radius << " Perimeter = " << perimeter() << " Surface = " << surface() << endl; 
}

float Circle::perimeter()const
{
    return 2 * M_PI * m_radius;
}

float Circle::surface()const
{
    return M_PI * pow(m_radius, 2);
}
