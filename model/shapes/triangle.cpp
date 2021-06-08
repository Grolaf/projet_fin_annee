#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"

using namespace std;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3, const string& label): Forme(label), m_p1(p1),m_p2(p2),m_p3(p3)
{
    printf("Triangle (défini)\n");
}

Triangle::Triangle(): Forme(), m_p1(0,0),m_p2(0,0),m_p3(0,0)
{
    printf("Triangle (defaut)\n");
}

Triangle::Triangle(const Triangle& c): Forme(c.GetLabel()), m_p1(c.m_p1), m_p2(c.m_p2), m_p3(c.m_p3)
{
    printf("Triangle (copie)\n");
}

Triangle::~Triangle()
{
    printf("~Triangle\n");
}


Triangle& Triangle::operator=(const Triangle& c)
{
    if(m_label != nullptr)
    {
        delete m_label;
    }

    m_label = new string(c.GetLabel());
    m_p1 = c.m_p1;
    m_p2 = c.m_p2;
    m_p3 = c.m_p3;

    return (*this);
}

void Triangle::display()const
{
    cout << "Triangle " << *m_label << " : ";
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