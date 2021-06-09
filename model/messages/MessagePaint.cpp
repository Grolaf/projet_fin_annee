//
// Created by barriean on 09/06/2021.
//

#include "MessagePaint.hpp"


MessagePaint::MessagePaint(MessagesTypes t, int coordinateX, int coordinateY, int size): Message(t), m_coordinateX(coordinateX), m_coordinateY(coordinateY), m_size(size) {}

MessagePaint::~MessagePaint(){}

void MessagePaint::setX(int x) {
    m_coordinateX = x;
}
void MessagePaint::setY(int y) {
    m_coordinateY = y;
}
void MessagePaint::setSize(int s) {
    m_size = s;
}

int MessagePaint::getX() const {
    return m_coordinateX;
}
int MessagePaint::getY() const {
    return m_coordinateY;
}
int MessagePaint::getSize() const {
    return m_size;
}


