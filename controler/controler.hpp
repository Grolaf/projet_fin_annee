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
    void paintBoard(int x, int y, int size);
    void refreshBoard();

};

#endif
