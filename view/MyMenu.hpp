#ifndef __MYMENU__
#define __MYMENU__

// inclusion of wx
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


// inclusion of specialize wx
#include "wx/wxprec.h"
#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/chartype.h>
#include <wx/bitmap.h>

#include "MyDrawingPanel.hpp"
#include "MyControlPanel.hpp"


#include "../view/Observed.hpp"




class MyMenu : public wxMenu{
public :
    MyMenu();
};

#endif