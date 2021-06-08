#ifndef __DAO_HPP_INCLUDED
#define __DAO_HPP_INCLUDED

#include <iostream>

class Dao
{
    public :
    ///// TODO : changer le type de retour pour envoyer les données
        static FILE* OpenFile(std::string fileName);
        
    ///// TODO : write in file
    
        static bool SaveFile(std::string fileName);
};

#endif
