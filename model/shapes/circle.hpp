#ifndef __CERCLE_H_INCLUDED
#define __CERCLE_H_INCLUDED

#include "shape.hpp"
#include "point.hpp"
#include "rectangle.hpp"

class Circle : public Shape
{
    private : 
        Point m_center;
        int m_radius;

    public : 

        Circle(int x, int y, int radius, std::string label = "", MyRGB color = MyRGB(0, 0, 0),MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1,  bool filled = false);
        Circle();
        virtual ~Circle();


    /*************************************************/
    /*      getters    */
        Point getCenter() const;
        int getRadius() const;
        Rectangle* getRectangleEnglobant() const;
        bool isCircle()const{return true;};
        bool isInside(int x, int y)const {return getRectangleEnglobant()->isInside(x, y);};

    /*************************************************/
    /*      setters    */
        void setCenter(int x, int y);
        void setRadius(int r);

    /*************************************************/
    /*      Usual Methods    */

        virtual void display()const;
        virtual float perimeter()const;
        virtual float surface()const;
        void move(int xTranslate, int yTranslate);

};


#endif
