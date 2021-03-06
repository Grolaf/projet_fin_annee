//
// Created by barriean on 09/06/2021.
//

#include "MessagePaint.hpp"


MessagePaint::MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int size, MyRGB color, MyRGB borderColor, int borderSize, bool filled): Message(t), m_coordinateX(coordinateX), m_coordinateY(coordinateY), m_width(size), m_height(size), m_radius(size), m_color(color) , m_borderColor(borderColor), m_borderSize(borderSize), m_filled(filled) {}

MessagePaint::MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int width, int height, MyRGB color, bool filled) : Message(t), m_coordinateX(coordinateX), m_coordinateY(coordinateY), m_width(width), m_height(height),m_radius(width),  m_color(color), m_filled(filled){}


MessagePaint::~MessagePaint(){}


int MessagePaint::getX() const {
    return m_coordinateX;
}
int MessagePaint::getY() const {
    return m_coordinateY;
}
int MessagePaint::getWidth() const {
    return m_width;
}
int MessagePaint::getHeight() const {
    return m_height;
}
int MessagePaint::getRadius() const {
    return m_radius;
}
MyRGB MessagePaint::getShapeColor() const {
    return m_color;
}
MyRGB MessagePaint::getBorderColor  () const {
    return m_borderColor;
}
int MessagePaint::getBorderSize() const {
    return m_borderSize;
}
bool MessagePaint::getFilled() const {
    return m_filled;
}


