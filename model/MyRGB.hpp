//
// Created by barriean on 09/06/2021.
//

#ifndef SKELETON_MYRGB_HPP
#define SKELETON_MYRGB_HPP

#include <iostream>

class MyRGB {

public:

    unsigned char red;
    unsigned char green;
    unsigned char blue;

    MyRGB(unsigned char r, unsigned char g, unsigned char b);
    MyRGB();

    ~MyRGB() = default;

    void write(std::ostream& file) const;
    void read(std::istream& file);


};


#endif //SKELETON_MYRGB_HPP
