//
// Created by antoine on 12/06/2021.
//

#include "MessageShape.h"

MessageShape::MessageShape(MessagesTypes type, Shape *shape) : Message(type), m_shape(shape){}

// On ne veut supprimer la forme que le message contient
MessageShape::~MessageShape(){}