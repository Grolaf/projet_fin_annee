#ifndef __FORME_H_INCLUDED__
#define __FORME_H_INCLUDED__

#include <string>
#include "../MyRGB.hpp"

class Shape
{
    public :

        Shape(std::string label, MyRGB color = MyRGB(0, 0, 0), bool filled = false);
        Shape();
        virtual ~Shape();
        Shape(const Shape& f);
        Shape& operator=(const Shape& f);

        void SetLabel(const std::string str);
        std::string GetLabel() const;
        MyRGB GetColor() const;
        bool isFilled() const;
        void SetColor(int r, int g, int b);
        virtual void display()const;
        virtual float perimeter()const = 0;
        virtual float surface()const = 0;

        virtual bool isRectangle() {return false;};
        virtual bool isCircle() {return false;};
        virtual bool isTriangle() {return false;};

    protected:

        std::string m_label;
        MyRGB m_color;
        bool m_filled;

};

#endif
