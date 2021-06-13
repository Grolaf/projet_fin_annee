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

        static int typeID;

        Circle(int x, int y, int radius,  MyRGB color = MyRGB(0, 0, 0),MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1,  bool filled = false);
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

        virtual float perimeter()const;
        virtual float surface()const;
        void move(int xTranslate, int yTranslate);
        void write(std::ostream& file) const;
        void read(std::istream& file);

    /*************************************************/
    /*      Class Methods    */

        static Circle* buildFromFile(std::istream& file);
};


#endif
