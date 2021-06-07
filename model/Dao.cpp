#include "Dao.hpp"

FILE* Dao::OpenFile(wxString fileName)
{
    try{
        FILE* f = fopen(fileName, "r");
    }catch(exception e)
    {
        throw "Error : file not found";
    }
    
    return f;    
}

bool Dao::SaveFile(wxString fileName)
{
    try{
        FILE* f = 
    }catch(exception e)
    {
        throw "Error : unable to write file";
    }

    ///// TODO : write in file
    
    fclose(f);

    return true;
}

