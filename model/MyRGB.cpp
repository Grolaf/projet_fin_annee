//
// Created by barriean on 09/06/2021.
//

#include "MyRGB.hpp"

MyRGB::MyRGB(unsigned char r, unsigned char g, unsigned char b): red(r), green(g), blue(b) {}

MyRGB::MyRGB(): red(0),green(0), blue(0) {}

void MyRGB::write(std::ostream &file) const
{
    file.write((char*)&red, sizeof(red));
    file.write((char*)&green, sizeof(green));
    file.write((char*)&blue, sizeof(blue));
}

void MyRGB::read(std::istream &file)
{
    file.read((char*)&red, sizeof(red));
    file.read((char*)&green, sizeof(green));
    file.read((char*)&blue, sizeof(blue));
}