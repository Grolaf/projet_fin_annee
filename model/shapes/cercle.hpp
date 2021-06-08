#ifndef __CERCLE_H_INCLUDED
#define __CERCLE_H_INCLUDED

#include "shape.hpp"
#include "point.hpp"

class Cercle : public Forme
{
    private : 
        Point m_center;
        int m_radius;

    public : 

        Cercle(int x, int y, int radius, std::string label);
        Cercle();
        virtual ~Cercle();
        Cercle(const Cercle& c);
        Cercle& operator=(const Cercle& c);

        virtual void display()const;
        virtual float perimeter()const;
        virtual float surface()const;
};


#endif
