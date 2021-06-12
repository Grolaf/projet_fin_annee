//
// Created by barriean on 09/06/2021.
//

#ifndef SKELETON_MYMODEL_HPP
#define SKELETON_MYMODEL_HPP

#include <stack>
#include "draw.hpp"

class MyModel
{
private:
    Draw* m_draw;
    Shape* m_copiedShape;
    std::vector<Shape*> m_undoRedoStack;

public:
    MyModel();
    ~MyModel() = default;

    /******   Getters ******/
    Draw* GetDraw();

    /******   Draw Functions *******/
    void AddRect(int x, int y , int witdh, int height, MyRGB color, MyRGB borderColor, int borderSize, bool filled);
    void AddCircle(int x, int y ,  int radius, MyRGB color, MyRGB borderColor, int borderSize,  bool filled);

    /******   Methods *******/

    void setCopiedShape(Shape* shape) {m_copiedShape = shape;};
    Shape* getSelection(int x, int y);
    void deleteShape(Shape* shape);
    void pasteCopiedShape();
    void undo();
    void redo();

};

#endif //SKELETON_MYMODEL_HPP
