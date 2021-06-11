#ifndef __CONTROLER_HPP_INCLUDED__
#define __CONTROLER_HPP_INCLUDED__

#include "Observer.hpp"
#include "../model/messages/Message.hpp"
#include "../view/MyFrame.hpp"
#include "../model/MyModel.hpp"

class Controler: public Observer
{

private :
    MyFrame* m_frame;
    MyModel* m_model;

    public :
        Controler(MyFrame* frame);
        ~Controler();
        virtual void treatMessage(Message *m);

private:

    /*************************************/
    /*   Setters */

    void AddRect(int x, int y, int width, int height, MyRGB color, MyRGB borderColor, int borderSize,  bool filled);
    void AddCircle(int x, int y,  int radius, MyRGB color, MyRGB borderColor, int borderSize, bool filled);

    /*************************************/
    /*   Usual Methods */

    void refreshBoard();
    void switchPrevisualize();
    void switchSelection();
    void selectShape(int x, int y);

};

#endif
