#ifndef __TRIANGLE_H_INCLUDED
#define __TRIANGLE_H_INCLUDED

#include "shape.hpp"
#include "point.hpp"
#include "rectangle.hpp"

class Triangle : public Shape
{
    private : 
        Point m_p1;
        Point m_p2;
        Point m_p3;

    public : 

        Triangle(const Point& p1, const Point& p2, const Point& p3, const std::string& label = "", MyRGB color = MyRGB(0, 0, 0), MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1, bool filled = false);
        Triangle();
        virtual ~Triangle();

    /*************************************************/
    /*      getters     */

        bool isTriangle(){return true;};
        Rectangle* getRectangleEnglobant() const;
        bool isInside(int x, int y)const {return getRectangleEnglobant()->isInside(x, y);};

    private :

        int getMinX() const;
        int getMinY() const;
        int getMaxX() const;
        int getMaxY() const;

    public:

    /*************************************************/
    /*      setters     */

    /*************************************************/
    /*      Usual Methods */
        virtual void display()const;
        virtual float perimeter()const;
        virtual float surface()const;
        void move(int xTranslate, int yTranslate);
};


#endif
