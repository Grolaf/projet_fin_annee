
// DEBOG

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

#include "../controler/controler.hpp"


//
#include "MyApp.hpp"
#include "MyFrame.hpp"

#include "../constants.hpp"

bool MyApp::OnInit()

{
  MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
  Controler* controler = new Controler(frame);
  frame->setObserver(controler);
  frame->GetDrawingPanel()->setObserver(controler);
  frame->GetControlPanel()->setObserver(controler);
  
  frame->Show(true); 
  SetTopWindow(frame);
  
  return true ;
}