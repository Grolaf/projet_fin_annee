#ifndef __FORME_H_INCLUDED__
#define __FORME_H_INCLUDED__

#include <string>
#include "../MyRGB.hpp"

class Shape
{
    public :

        Shape(std::string label, MyRGB color = MyRGB(0, 0, 0), MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1,  bool filled = false);
        Shape();
        virtual ~Shape();
        Shape(const Shape& f);
        Shape& operator=(const Shape& f);

    /*************************************************/
    /*      setters    */
        void SetLabel(const std::string str);
        void SetColor(MyRGB color){m_color = color;};
        void SetBorderColor(MyRGB color) {m_borderColor = m_borderColor;};
        void SetBorderSize(int size){m_borderSize = size;};

    /*************************************************/
    /*      getters    */

        std::string GetLabel() const;
        MyRGB GetColor() const {return m_color;};
        MyRGB GetBorderColor() const {return m_borderColor;};
        int GetBorderSize() const {return m_borderSize;};
        bool isFilled() const;

    /*************************************************/
    /*      Methods    */

        virtual void display()const;
        virtual float perimeter()const = 0;
        virtual float surface()const = 0;

    /*************************************************/
    /*      For casts    */

        virtual bool isRectangle() const{return false;};
        virtual bool isCircle() const {return false;};
        virtual bool isTriangle() const {return false;};
        virtual bool isInside(int x, int y)const = 0 ;

    protected:

        std::string m_label;
        MyRGB m_color;
        MyRGB m_borderColor;
        int m_borderSize;
        bool m_filled;

};

#endif
