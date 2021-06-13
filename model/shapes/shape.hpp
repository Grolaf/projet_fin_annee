#ifndef __SHAPE_HPP_INCLUDED__
#define __SHAPE_HPP_INCLUDED__

#include <string>
#include "../MyRGB.hpp"

class Rectangle;

class Shape
{
    public :

        Shape(MyRGB color = MyRGB(0, 0, 0), MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1,  bool filled = false);
        virtual ~Shape();
        Shape(const Shape& f);

    /*************************************************/
    /*      setters    */
        void SetColor(MyRGB color){m_color = color;};
        void SetBorderColor(MyRGB color) {m_borderColor = color;};
        void SetBorderSize(int size){m_borderSize = size;};

    /*************************************************/
    /*      getters    */

        MyRGB GetColor() const {return m_color;};
        MyRGB GetBorderColor() const {return m_borderColor;};
        int GetBorderSize() const {return m_borderSize;};
        virtual Rectangle* getRectangleEnglobant() const = 0;
        bool isFilled() const;

    /*************************************************/
    /*      Methods    */

        virtual float perimeter()const = 0;
        virtual float surface()const = 0;
        virtual void move(int xTranslate, int Ytranslate) = 0;
        virtual void write(std::ostream& file) const;
        virtual void read(std::istream& file);

    /*************************************************/
    /*      For casts    */

        virtual bool isRectangle() const{return false;};
        virtual bool isCircle() const {return false;};
        virtual bool isTriangle() const {return false;};
        virtual bool isInside(int x, int y)const = 0 ;

    protected:

        MyRGB m_color;
        MyRGB m_borderColor;
        int m_borderSize;
        bool m_filled;

};

#endif
