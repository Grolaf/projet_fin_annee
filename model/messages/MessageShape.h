//
// Created by antoine on 12/06/2021.
//

#ifndef SKELETON_MESSAGESHAPE_H
#define SKELETON_MESSAGESHAPE_H


#include "../shapes/shape.hpp"
#include "Message.hpp"

class MessageShape : public Message{

private:
    Shape* m_shape;

public:

    MessageShape(MessagesTypes type, Shape* shape);
    ~MessageShape();

    Shape* getShape() const {return m_shape;};
};


#endif //SKELETON_MESSAGESHAPE_H
