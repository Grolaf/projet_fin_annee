#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"

using namespace std;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3, const string& label, MyRGB color, MyRGB borderColor, int borderSize, bool filled): Shape(label, color,borderColor, borderSize,  filled), m_p1(p1), m_p2(p2), m_p3(p3)
{
}

Triangle::Triangle(): Shape(), m_p1(0, 0), m_p2(0, 0), m_p3(0, 0)
{
}


Triangle::~Triangle()
{
}

bool Triangle::isInside(int x, int y) const
{
    throw "not implemented";
}

void Triangle::display()const
{
    cout << "Triangle " << m_label << " : ";
    cout << " p1 = ";
    m_p1.Display();
    cout << ", p2 = ";
    m_p2.Display();
    cout << ", p3 = ";
    m_p3.Display();
    cout << "Perimeter = " << perimeter() << " Surface = " << surface() << endl;
}

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
