#include "Dao.hpp"
#include <cstdio>

using namespace std;

FILE* Dao::OpenFile(string fileName)
{
    cout << "Opening file" << endl;
 //   FILE* f;
 //   try{
 //       f = fopen(fileName, "r");
 //   }catch(...)
 //   {
 //       throw "Error : file not found";
 //   }
 //   
 //   return f;    
    return nullptr;
}

bool Dao::SaveFile(string fileName)
{
    cout << "Saving file" << endl;
   // FILE* f;
   // try{
   //     f = fopen(fileName, "r");
   // }catch(...)
   // {
   //     throw "Error : unable to write file";
   // }
   // 
   // fclose(f);

    return true;
}

