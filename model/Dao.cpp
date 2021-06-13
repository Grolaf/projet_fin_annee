#include "Dao.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

void Dao::LoadFile(const char* fileName, Draw* draw)
{
    filebuf fb;
    try{
        fb.open(fileName, ios::in | ios::binary);
    }catch(...)
    {
        throw "Error : file not found";
    }
    istream f(&fb);

    try {
        draw->read(f);
    }
    catch( ... )
    {
        throw "Error when reading draw";
    }

    fb.close();
}

void Dao::SaveFile(const char* fileName, Draw* draw)
{
    filebuf fb;
    try{
        fb.open(fileName, ios::out | ios::binary);
    }catch(...)
    {
        throw "Error : unable to write file";
    }

    ostream f(&fb);

    try {
        draw->write(f);
    }
    catch( ... )
    {
        throw "Error when writing draw";
    }

    fb.close();

}

