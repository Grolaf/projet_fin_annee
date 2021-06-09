//
// Created by barriean on 09/06/2021.
//

#ifndef SKELETON_MESSAGEPAINT_HPP
#define SKELETON_MESSAGEPAINT_HPP

#include "Message.hpp"

class MessagePaint : public Message
{
    private :
        int m_coordinateX;
        int m_coordinateY;
        int m_size;


    public:
        MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int size);
        ~MessagePaint();

        // Setters
        void setX(int x);
        void setY(int y);
        void setSize(int s);

        // Getters
        int getX() const;
        int getY() const;
        int getSize() const;

};


#endif //SKELETON_MESSAGEPAINT_HPP
