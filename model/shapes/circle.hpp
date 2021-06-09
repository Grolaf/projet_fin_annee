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

        Circle(int x, int y, int radius, std::string label, MyRGB color = MyRGB(0, 0, 0), bool filled = false);
        Circle();
        virtual ~Circle();
        Circle(const Circle& c);
        Circle& operator=(const Circle& c);

        virtual void display()const;
        virtual float perimeter()const;
        virtual float surface()const;

        Point getCenter() const;
        int getRadius() const;

        void setCenter(int x, int y);
        void setRadius(int r);
};


#endif
