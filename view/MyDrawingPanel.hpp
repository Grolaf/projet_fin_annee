
#ifndef __MYDRAWINGPANEL__
#define __MYDRAWINGPANEL__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel
           
{
public:
  MyDrawingPanel( wxWindow *parent ) ;

private:
  void OnMouseMove(wxMouseEvent &event) ;
  void OnMouseLeftDown(wxMouseEvent &event) ;
  void OnPaint(wxPaintEvent &event) ;
  wxPoint m_mousePoint ;
  wxPoint m_onePoint ;
};

#endif