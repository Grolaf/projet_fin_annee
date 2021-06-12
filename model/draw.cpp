#include "draw.hpp"

Draw::Draw(){
    m_shapes;
}

Draw::~Draw()
{
    std::vector<Shape*>::iterator it;

    for(it = m_shapes.begin(); it < m_shapes.end(); it++)
    {
        delete *it;
    }
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
    it = m_shapes.rbegin();

    // Cet algorithme utilise la surface minimale de l'élément sur lequel a cliqué l'utilisateur (de façon a pouvoir sélectionner un petit objet qui serait à coté d'un gros)
    Shape* shapeSelected = nullptr;

    for(it = m_shapes.rbegin(); it < m_shapes.rend(); it++)
    {
        if((*it)->isInside(x, y) && (shapeSelected == nullptr || (*it)->surface() < shapeSelected->surface()))
        {
            shapeSelected = *it;
        }
    }

    return shapeSelected;
}

/*************************************************/
/*      setters    */

void Draw::addShape(Shape *s)
{
    m_shapes.push_back(s);
}

/*************************************************/
/*      Usual Methods    */

void Draw::deleteShape(Shape* shape)
{
    std::vector<Shape*>::iterator it;

    for(it = m_shapes.begin(); it < m_shapes.end(); it++)
    {
        if(*it == shape)
        {
            m_shapes.erase(it);
        }
    }

    m_shapes.shrink_to_fit();
}


Shape* Draw::deleteLastShape()
{
    if(m_shapes.size() != 0) {
        Shape *toReturn = m_shapes.back();
        m_shapes.pop_back();

        return toReturn;
    }
    return nullptr;
}
