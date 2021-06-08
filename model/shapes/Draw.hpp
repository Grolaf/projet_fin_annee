//
// Created by barriean on 08/06/2021.
//

#ifndef SKELETON_DRAW_HPP
#define SKELETON_DRAW_HPP

#include "shape.hpp"
#include <vector>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

class Draw
{
    private:
        std::vector<Rectangle> rectangles;
        std::vector<Triangle> triangles;
        std::vector<Circle> cercles;

    public:

        Draw();
        ~Draw() = default;

        void addRectangle(Rectangle r);
        void addTriangle(Triangle t);
        void addCircle(Circle c);
        
};

#endif //SKELETON_DRAW_HPP
