#include "draw.hpp"

Draw::Draw(){
    m_rectangles;
    m_triangles;
    m_circles;
}

/*************************************************/
/*      getters    */

std::vector<Rectangle> Draw::getRectangles() const
{
    return m_rectangles;
}

std::vector<Triangle> Draw::getTriangles() const
{
    return m_triangles;
}
std::vector<Circle> Draw::getCircles() const
{
    return m_circles;
}

/*************************************************/
/*      setters    */

void Draw::addRectangle(Rectangle &r)
{
    m_rectangles.push_back(r);
}
void Draw::addTriangle(Triangle &t)
{
    m_triangles.push_back(t);
}
void Draw::addCircle(Circle &c)
{
    m_circles.push_back(c);
}

void Draw::deleteRectangle(std::string label)
{
}
void Draw::deleteTriangle(std::string label)
{

}
void Draw::deleteCircle(std::string label)
{

}

/*************************************************/
/*      Usual Methods    */

