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




class MyApp: public wxApp
  {
    virtual bool OnInit() ;
  };
  
  
#endif