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

Shape* Draw::getSelection(int x, int y)
{
    std::vector<Shape*>::reverse_iterator it;

    for(it = m_shapes.rbegin(); it < m_shapes.rend(); it++)
    {
        if((*it)->isInside(x, y))
        {
            return *it;
        }
    }

    return nullptr;
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

