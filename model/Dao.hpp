#ifndef __DAO_HPP_INCLUDED
#define __DAO_HPP_INCLUDED

#include <iostream>
#include "draw.hpp"

class Dao
{
    public :
        static void LoadFile(const char* fileName, Draw* draw);

        static void SaveFile(const char* fileName, Draw* draw);
};

#endif
