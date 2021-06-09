
#ifndef __MYDRAWINGPANEL__
#define __MYDRAWINGPANEL__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "../model/shapes/rectangle.hpp"
#include "../model/shapes/triangle.hpp"
#include "../model/shapes/circle.hpp"
#include "Observed.hpp"
#include "../model/draw.hpp"

#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <vector>

//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel, public Observed
           
{
public:
  MyDrawingPanel( wxWindow *parent ) ;

  void PaintRect(std::vector<Rectangle> rectangles);
  void PaintTriangle(std::vector<Triangle> triangles);
  void PaintCircle(std::vector<Circle> circles);

private:

    /*****  Draw functions ******/
  void OnMouseMove(wxMouseEvent &event) ;
  void OnMouseLeftDown(wxMouseEvent &event) ;
  void OnPaint(wxPaintEvent &event) ;

  /****** Attributes *****/
  wxPoint m_mousePoint ;
  wxPoint m_onePoint ;
};

#endif