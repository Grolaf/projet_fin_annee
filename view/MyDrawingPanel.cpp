
#include "MyDrawingPanel.hpp"
#include "MyFrame.hpp"


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

#include "../constants.hpp"

using namespace std;
//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent), Observed()
  //------------------------------------------------------------------------
  // In this constructor, bind some mouse events and the paint event with the appropriate methods
{
  int w, h ;
  GetParent()->GetClientSize(&w,&h) ;
  SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
  SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
  Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
  Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
  Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
  m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
  m_onePoint.y = h/2 ;
  m_mousePoint = m_onePoint ;
}

void MyDrawingPanel::PaintRect(std::vector<Rectangle> rectangles) {
    wxPaintDC dc(this);
    vector<Rectangle>::iterator it;

    for(it = rectangles.begin(); it < rectangles.end(); it++)
    {
        dc.SetPen(wxColor(255, 0, 0));
        dc.DrawRectangle(wxPoint(it->getCorner().GetX(), it->getCorner().GetY()), wxSize(it->getWidth(),it->getHeight())) ;
    }
}



//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
  //------------------------------------------------------------------------
  // called when the mouse is moved
{
	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
  //------------------------------------------------------------------------
  // called when the mouse left button is pressed
{
    Message* m = new Message(PAINT);
    notifyObserver(m);
    delete m;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
  //------------------------------------------------------------------------
  // called automatically when the panel is shown for the first time or
  // when the panel is resized
  // You have to call OnPaint with Refresh() when you need to update the panel content
{
  // read the control values
  MyFrame* frame =  (MyFrame*)GetParent() ;
  int radius = frame->GetControlPanel()->GetSliderValue() ;
  bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
  
  // then paint
  wxPaintDC dc(this);	
  
  dc.DrawLine(m_mousePoint, m_onePoint) ;
  dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
  dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;
  
  if (check)
  {
    wxString coordinates ;
    coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
    dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
  }
}
