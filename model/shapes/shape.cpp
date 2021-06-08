#include "shape.hpp"
#include <iostream>

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Shape::Shape(string label)
{
    m_label = new string(label);
}

Shape::Shape()
{
    m_label = new string();
}

Shape::Shape(const Shape& f)
{
    SetLabel(f.GetLabel());
}

Shape& Shape::operator=(const Shape &f)
{
    SetLabel(f.GetLabel());
    return (*this);
}

Shape::~Shape()
{
    if(m_label != NULL)
    {
        delete m_label;
    }
}

/***************************************************************************************/
/*      getters        */

string Shape::GetLabel() const
{
    return *m_label;
}

/***************************************************************************************/
/*      setters        */

void Shape::SetLabel(const string &str)
{
    if(m_label != nullptr)
    {
        delete m_label;
    }
    m_label = new string(str);
}

/***************************************************************************************/
/*      methods        */

void Shape::display()const
{
    cout << "Shape " << *m_label << endl;
}
