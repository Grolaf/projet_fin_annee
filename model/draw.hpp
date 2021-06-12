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
        std::vector<Shape*> m_shapes;

    public:

        Draw();
        ~Draw();

    /*************************************************/
    /*      getters    */

        std::vector<Shape*> getShapes() const;
        Shape* getSelection(int x, int y);

    /*************************************************/
    /*      setters    */

        void addShape(Shape *shape);


    /*************************************************/
    /*      Usual Methods    */

        Shape* deleteLastShape();
        void deleteShape(Shape* shape);

};

#endif //SKELETON_DRAW_HPP
