
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

#include "myDrawingPanel.hpp"
#include "myControlPanel.hpp"

#define APPLICATION_WIDTH	700
#define APPLICATION_HEIGHT	600
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
//
#include "myApp.hpp"
#include "myFrame.hpp"

bool MyApp::OnInit()

{
  MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
  Controler* controler = new Controler();
  frame->setObserver(controler);
  
  frame->Show(true); 
  SetTopWindow(frame);
  
  return true ;
}