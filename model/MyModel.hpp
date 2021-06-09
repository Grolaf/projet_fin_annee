//
// Created by barriean on 09/06/2021.
//

#ifndef SKELETON_MYMODEL_HPP
#define SKELETON_MYMODEL_HPP

#include "shapes/draw.hpp"

class MyModel
{
private:
    Draw* m_draw;

public:
    MyModel();
    ~MyModel() = default;

    /******   Getters ******/
    Draw* GetDraw();

    /******   Draw Functions *******/
    void AddRect(int x, int y , int witdh, int height);

};

#endif //SKELETON_MYMODEL_HPP
