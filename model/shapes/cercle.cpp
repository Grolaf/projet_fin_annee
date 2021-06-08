#include <cmath>
#include <iostream>
#include "shape.hpp"
#include "cercle.hpp"

using namespace std;

Cercle::Cercle(int x, int y, int radius, string label): Forme(label), m_center(x, y),m_radius(radius)
{
    printf("Cercle (défini)\n");
}

Cercle::Cercle(): Forme(), m_center()
{
    m_radius = 0;

    printf("Cercle (defaut)\n");
}
Cercle::Cercle(const Cercle& c): Forme(c.GetLabel()), m_center(c.m_center), m_radius(c.m_radius)
{
    printf("Cercle (copie)\n");
}

Cercle::~Cercle()
{
    printf("~Cercle\n");
}


Cercle& Cercle::operator=(const Cercle& c)
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

void Cercle::display()const
{
    cout << "Cercle " << *m_label << " : ";
    m_center.Display();
    cout << " radius = " << m_radius << " Perimeter = " << perimeter() << " Surface = " << surface() << endl; 
}

float Cercle::perimeter()const
{
    return 2 * M_PI * m_radius;
}

float Cercle::surface()const
{
    return M_PI * pow(m_radius, 2);
}
