#ifndef __MYAPP__
#define __MYAPP__



// inclusion of wx
#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

// inclusion of specialize wx
#include "wx/wxprec.h"
#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

// inclusion of Message mod
#include "../model/messages/MessageFile.hpp"
#include "../model/messages/MessagesTypes.hpp"
#include "../model/messages/MessageFile.hpp"
#include "../model/Dao.hpp"

// inclusion of views

#include "../view/Observed.hpp"

// inclusion of controller
#include "../controler/Observer.hpp"
#include "../controler/controler.hpp"
  

  
class MyApp: public wxApp
  {
    virtual bool OnInit() ;
  };
  
  
#endif