#include "draw.hpp"

Draw::Draw(){
    m_shapes;
}

/*************************************************/
/*      getters    */

std::vector<Shape*> Draw::getShapes() const
{
    return m_shapes;
}

/*************************************************/
/*      setters    */

void Draw::addShape(Shape *s)
{
    m_shapes.push_back(s);
}

void Draw::deleteShape() {}



/*************************************************/
/*      Usual Methods    */

