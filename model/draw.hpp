//
// Created by barriean on 08/06/2021.
//

#ifndef SKELETON_DRAW_HPP
#define SKELETON_DRAW_HPP

#include "shapes/shape.hpp"
#include <vector>
#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/triangle.hpp"

class Draw
{
    private:
        std::vector<Rectangle> m_rectangles;
        std::vector<Triangle> m_triangles;
        std::vector<Circle> m_circles;

    public:

        Draw();
        ~Draw() = default;

    /*************************************************/
    /*      getters    */

        std::vector<Rectangle> getRectangles() const;
        std::vector<Triangle> getTriangles() const;
        std::vector<Circle> getCircles() const;

    /*************************************************/
    /*      setters    */

        void addRectangle(Rectangle &r);
        void addTriangle(Triangle &t);
        void addCircle(Circle &c);

        void deleteRectangle(std::string label);
        void deleteTriangle(std::string label);
        void deleteCircle(std::string label);

    /*************************************************/
    /*      Usual Methods    */


};

#endif //SKELETON_DRAW_HPP
