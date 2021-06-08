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




class MyFrame: public wxFrame, public Observed

{
  public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
    void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;
  
protected:
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
  void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
  void OnClose(wxCloseEvent& event) ;
  void OnSize(wxSizeEvent &event) ;
  
  MyControlPanel *m_controlPanel; // the panel with controls
  MyDrawingPanel *m_drawingPanel; // the panel in which we draw
} ;





#endif