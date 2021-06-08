#ifndef __FORME_H_INCLUDED__
#define __FORME_H_INCLUDED__

#include <string>

class Shape
{
    public :

        Forme(std::string label);
        Forme();
        virtual ~Forme();
        Forme(const Forme& f);
        Forme& operator=(const Forme& f);

        void SetLabel(const std::string& str);
        std::string GetLabel() const;
        virtual void display()const;
        virtual float perimeter()const = 0;
        virtual float surface()const = 0;
    protected:

        std::string* m_label;

};

#endif
