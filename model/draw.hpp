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
        ~Draw() = default;

    /*************************************************/
    /*      getters    */

        std::vector<Shape*> getShapes() const;

    /*************************************************/
    /*      setters    */

        void addShape(Shape *s);

        void deleteShape();

    /*************************************************/
    /*      Usual Methods    */


};

#endif //SKELETON_DRAW_HPP
