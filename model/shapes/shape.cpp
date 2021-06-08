#include "shape.hpp"
#include <iostream>

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Forme::Forme(string label)
{
    printf("Forme (défini)\n");
    m_label = new string(label);
}

Forme::Forme()
{
    printf("Forme (defaut)\n");
    m_label = new string();
}

Forme::Forme(const Forme& f)
{
    printf("Forme (copie)\n");
    SetLabel(f.GetLabel());
}

Forme& Forme::operator=(const Forme &f)
{
    printf("Forme (affectation)\n" );
    SetLabel(f.GetLabel());
    return (*this);
}

Forme::~Forme()
{
    printf("~Forme()\n");
    if(m_label != NULL)
    {
        delete m_label;
    }
}

/***************************************************************************************/
/*      getters        */

string Forme::GetLabel() const
{
    return *m_label;
}

/***************************************************************************************/
/*      setters        */

void Forme::SetLabel(const string &str)
{
    if(m_label != nullptr)
    {
        delete m_label;
    }
    m_label = new string(str);
}

/***************************************************************************************/
/*      methods        */

void Forme::display()const
{
    cout << "Forme " << *m_label << endl;
}
