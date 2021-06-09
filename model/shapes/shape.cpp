#include "shape.hpp"
#include <iostream>

using namespace std;

/***************************************************************************************/
/*      Builders and Destructors        */

Shape::Shape(string label)
{
    m_label = label;
}

Shape::Shape()
{
    m_label = "";
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
}

/***************************************************************************************/
/*      getters        */

string Shape::GetLabel() const
{
    return m_label;
}

/***************************************************************************************/
/*      setters        */

void Shape::SetLabel(const string str)
{
    m_label = str;
}

/***************************************************************************************/
/*      methods        */

void Shape::display()const
{
    cout << "Shape " << m_label << endl;
}
