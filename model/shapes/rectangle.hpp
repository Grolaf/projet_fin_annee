#ifndef __RECTANGLE_H_INCLUDED__
#define __RECTANGLE_H_INCLUDED__

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


        Rectangle(int xLeftCorner, int yLeftCorner, int width, int height, std::string label, MyRGB color = MyRGB(0, 0, 0), bool filled = false);
        Rectangle(Point& p, int width, int height);
        virtual ~Rectangle();

        /*************************************************/
        /*      getters    */

        int getWidth() const;
        int getHeight() const;
        int* getDimensions()const;
        Point& getCorner();


        /*************************************************/
        /*      setters    */

        void setDimensions(int width, int height);
        void setCorner(int xLeftCorner, int yLeftCorner);
        void setCorner(Point& p);

        /*************************************************/
        /*      Usuals methods    */

        void Move(int x, int y);
        bool isInside(Rectangle& r) const;
        int Surface() const;

        virtual void display() const;
        virtual float perimeter()const;
        virtual float surface()const;

        /*************************************************/
        /*      class methods    */
        
        static int GetRectCount();
};

#endif
