#ifndef __RECTANGLE_HPP_INCLUDED__
#define __RECTANGLE_HPP_INCLUDED__

#include "shape.hpp"
#include "point.hpp"

class Rectangle: public Shape
{
    private :

        Point m_corner;
        int m_w;
        int m_h;

        static int m_rectCount;


    public :


        Rectangle(int xLeftCorner, int yLeftCorner, int width, int height, std::string label = "", MyRGB color = MyRGB(0, 0, 0), MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1, bool filled = false);
        Rectangle(Point& p, int width, int height);
        virtual ~Rectangle();

        /*************************************************/
        /*      getters    */

        int getWidth() const;
        int getHeight() const;
        int* getDimensions()const;
        Point& getCorner();
        Rectangle* getRectangleEnglobant()const;
        bool isRectangle()const {return true;};
        bool isInside(int x, int y) const;

        /*************************************************/
        /*      setters    */

        void setDimensions(int width, int height);
        void setCorner(int xLeftCorner, int yLeftCorner);
        void setCorner(Point& p);

        /*************************************************/
        /*      Usuals methods    */

        void move(int xTranslate, int yTranslate);
        int Surface() const;

        virtual void display() const;
        virtual float perimeter()const;
        virtual float surface()const;

        /*************************************************/
        /*      class methods    */
        
        static int GetRectCount();
};

#endif
