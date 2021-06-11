#ifndef __MYFRAME__
#define __MYFRAME__

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
#include "MyMenu.hpp"




class MyFrame: public wxFrame, public Observed

{
  public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
    MyDrawingPanel* GetDrawingPanel(){return m_drawingPanel;};
    void RefreshDrawing();
    void RefreshCoord(wxMouseEvent &event);

protected:
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
  void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;

  void OnClose(wxCloseEvent& event) ;
  void OnSize(wxSizeEvent &event) ;

  //wxBoxSizer *sizer;
  MyControlPanel *m_controlPanel; // the panel with controls
  MyDrawingPanel *m_drawingPanel; // the panel in which we Draw
  MyMenu *filemenu;
} ;





#endif