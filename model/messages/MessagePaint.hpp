//
// Created by barriean on 09/06/2021.
//

#ifndef SKELETON_MESSAGEPAINT_HPP
#define SKELETON_MESSAGEPAINT_HPP

#include "Message.hpp"
#include "../MyRGB.hpp"

class MessagePaint : public Message
{
    private :
        int m_coordinateX;
        int m_coordinateY;
        int m_width;
        int m_height;
        int m_radius;
        MyRGB m_color;
        MyRGB m_borderColor;
        int m_borderSize;
        bool m_filled;


    public:
        MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int size = 0, MyRGB color = MyRGB(0, 0, 0), MyRGB borderColor = MyRGB(0, 0, 0), int borderSize = 1, bool filled = false);
        MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int width, int height, MyRGB color, bool filled);
        ~MessagePaint();

        // Setters

        // Getters
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        int getRadius() const;
        MyRGB getShapeColor() const;
        MyRGB getBorderColor() const;
        int getBorderSize() const;
        bool getFilled() const;

};


#endif //SKELETON_MESSAGEPAINT_HPP
