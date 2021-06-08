#ifndef __CERCLE_H_INCLUDED
#define __CERCLE_H_INCLUDED

#include "shape.hpp"
#include "point.hpp"

class Circle : public Shape
{
    private : 
        Point m_center;
        int m_radius;

    public : 

        Circle(int x, int y, int radius, std::string label);
        Circle();
        virtual ~Circle();
        Circle(const Circle& c);
        Circle& operator=(const Circle& c);

        virtual void display()const;
        virtual float perimeter()const;
        virtual float surface()const;
};


#endif