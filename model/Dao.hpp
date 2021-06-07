#ifndef __DAO_HPP_INCLUDED
#define __DAO_HPP_INCLUDED

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <iostream>

class Dao
{
    public :
    ///// TODO : changer le type de retour pour envoyer les données
        static FILE* OpenFile(wxString fileName);
        
    ///// TODO : write in file
    
        static bool SaveFile(wxString fileName);
};

#endif
