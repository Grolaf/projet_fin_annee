
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

  /*****  Draw functions ******/
  void PaintRect(wxPaintDC &dc, Rectangle *r);
  void PaintTriangle(wxPaintDC &dc, Triangle *t);
  void PaintCircle(wxPaintDC &dc, Circle *c);

    /*****  Getters ******/
    wxPoint &getMouse (){return m_mousePoint;};
    bool getPrevisualize()const{return m_previsualize;};

  /*****  Setters ******/
  void switchPevisualize(){m_previsualize = !m_previsualize;};
  void switchSelection(){m_selection = !m_selection;};
  void setSelectedShape(Shape* shape) { m_selectedElement = shape;};
  void setDraw(Draw* draw) {m_draw = draw;};


  /*****  Methods ******/
  void Previsualize();

  /*****  Public ActionFunctions ******/
  void OnKeyDown(wxKeyEvent &event) ;

private:

  /*****  ActionFunctions ******/
  void OnMouseMove(wxMouseEvent &event) ;
  void OnMouseLeftDown(wxMouseEvent &event) ;
  void OnMouseLeftUp(wxMouseEvent &event) ;

  // A implémenter : pour pouvoir facilement prévisualiser la forme
  void OnMouseLeft(wxMouseEvent &event);
  void OnMouseIn(wxMouseEvent &event);
  void OnPaint(wxPaintEvent &event) ;

  /****** Attributes *****/
  wxPoint m_mousePoint ;
  wxPoint m_onePoint ;

  Shape* m_selectedElement;
  Draw* m_draw;

  bool m_previsualize;
  bool m_selection;
  bool m_moveObject;
};

#endif