
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
#include "../model/messages/MessagePaint.hpp"

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
    m_previsualize = false;
    m_selection = false;
}


//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
    m_mousePoint.x = event.m_x;
    m_mousePoint.y = event.m_y;
    if (m_previsualize)
    {
        Message *m = new Message(REFRESH);
        notifyObserver(m);
        delete m;
    }
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
    if (m_selection) {
        MessagePaint* m = new MessagePaint(SELECT, m_mousePoint.x, m_mousePoint.y);
        notifyObserver(m);
        delete m;
    } else
    {
        MyFrame *frame = (MyFrame *) GetParent();
        // Chargement des paramètres dans le MyControlPanel
        int size = frame->GetControlPanel()->GetShapeSize();
        int borderSize = frame->GetControlPanel()->GetBorderSize();
        wxColor colorFill = frame->GetControlPanel()->GetShapeColour();
        MyRGB color(colorFill.Red(), colorFill.Green(), colorFill.Blue());
        wxColor colorB = frame->GetControlPanel()->GetBorderColour();
        MyRGB colorBorder(colorB.Red(), colorB.Green(), colorB.Blue());
        bool filled = frame->GetControlPanel()->GetCheckBoxFillShapeValue();

        wxString selectedShape = frame->GetControlPanel()->GetSelectedShape();

        if (selectedShape.IsSameAs("Carre")) {
            MessagePaint *m = new MessagePaint(PAINT_RECT, m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size,color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        } else if (selectedShape.IsSameAs("Rectangle")) {
            MessagePaint *m = new MessagePaint(PAINT_RECT, m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size,color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        } else if (selectedShape.IsSameAs("Cercle")) {
            MessagePaint *m = new MessagePaint(PAINT_CIRCLE, m_mousePoint.x, m_mousePoint.y, size,color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        } else if (selectedShape.IsSameAs("Ellipse")) {
            MessagePaint *m = new MessagePaint(PAINT_RECT, m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size, color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        } else if (selectedShape.IsSameAs("Ligne")) {
            MessagePaint *m = new MessagePaint(PAINT_LINE, m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size,color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        } else if (selectedShape.IsSameAs("Polygone")) {
            MessagePaint *m = new MessagePaint(PAINT_POLYGON, m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size,color, colorBorder, borderSize, filled);
            notifyObserver(m);
            delete m;
        }
    }
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
    bool check = frame->GetControlPanel()->GetCheckBoxTextValue() ;

    // then paint
    wxPaintDC dc(this);

    std::vector<Shape*>::iterator it;
    std::vector<Shape*> shapes = m_draw->getShapes();
    Rectangle* r = nullptr;
    Circle* c = nullptr;
    Triangle* t = nullptr;

    // Dessin avec cast des formes
    for(it = shapes.begin(); it < shapes.end(); it++) {
        if((*it)->isRectangle())
        {
            r = dynamic_cast<Rectangle*>(*it);
            PaintRect(dc, r);
        }
        else if((*it)->isCircle())
        {
            c = dynamic_cast<Circle*>(*it);
            PaintCircle(dc, c);
        }
    }

    if(m_selection && m_selectedElement != nullptr) {
        // Dessin de la forme selectionnée
        if (m_selectedElement->isRectangle()) {
            r = dynamic_cast<Rectangle *>(m_selectedElement);
            Rectangle rect = *r;
            rect.SetBorderColor(MyRGB(125, 125, 0));
            rect.SetBorderSize(4);

        } else if (m_selectedElement->isCircle()) {
            c = dynamic_cast<Circle *>(m_selectedElement);
            PaintCircle(dc, c);
        }
    }

    if (check)
    {
        wxString coordinates ;
        coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
        dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
    }

    if(m_previsualize)
        Previsualize();

}

void MyDrawingPanel::PaintRect(wxPaintDC &dc, Rectangle *r) {

    wxColour borderColor(r->GetBorderColor().red, r->GetBorderColor().green, r->GetBorderColor().blue);
    wxColour shapeColor(r->GetColor().red, r->GetColor().green, r->GetColor().blue);
    wxPen pen(borderColor, r->GetBorderSize());
    dc.SetPen(pen);

    if (r->isFilled()) {
        dc.SetBrush(shapeColor);
    }
    else
    {
        dc.SetBrush(*wxTRANSPARENT_BRUSH);
    }
    dc.DrawRectangle(wxPoint(r->getCorner().GetX(), r->getCorner().GetY()), wxSize(r->getWidth(), r->getHeight()));

}
void MyDrawingPanel::PaintTriangle(wxPaintDC &dc, Triangle *t) {

    //vector<Triangle>::iterator it;
    // for(it = triangles.begin(); it < triangles.end(); it++)
    // {
    //     dc.SetPen(wxColor(it->GetColor().red, it->GetColor().green, it->GetColor().blue));
    //     dc.DrawRectangle(wxPoint(it->getCorner().GetX(), it->getCorner().GetY()), wxSize(it->getWidth(),it->getHeight())) ;
    // }

}
void MyDrawingPanel::PaintCircle(wxPaintDC &dc, Circle *c) {

    wxColour borderColor(c->GetBorderColor().red, c->GetBorderColor().green, c->GetBorderColor().blue);
    wxColour shapeColor(c->GetColor().red, c->GetColor().green, c->GetColor().blue);
    wxPen pen(borderColor, c->GetBorderSize());
    dc.SetPen(pen);

    if(c->isFilled())
    {
        dc.SetBrush(shapeColor);
    } else
    {
        dc.SetBrush(*wxTRANSPARENT_BRUSH);
    }

    dc.DrawCircle(wxPoint(c->getCenter().GetX() , c->getCenter().GetY() ), c->getRadius()) ;
}
void MyDrawingPanel::Previsualize() {

    MyFrame* frame = (MyFrame*) GetParent();
    wxPaintDC dc(this);

//Chargement des paramètres dans le controlpanel
    int size = frame->GetControlPanel()->GetShapeSize();
    int borderSize = frame->GetControlPanel()->GetBorderSize();
    wxColor colorFill = frame->GetControlPanel()->GetShapeColour();
    MyRGB color(colorFill.Red(), colorFill.Green(), colorFill.Blue());
    wxColor colorB = frame->GetControlPanel()->GetBorderColour();
    MyRGB colorBorder(colorB.Red(), colorB.Green(), colorB.Blue());
    bool filled = frame->GetControlPanel()->GetCheckBoxFillShapeValue();
    dc.SetPen(colorFill);

    wxString selectedShape = frame->GetControlPanel()->GetSelectedShape();

    // Ici on envoie chaque fois l'adresse de l'objet, puisque cela ne gêne pas qu'il soit détruit (il sert juste à la prévisualisation
    if (selectedShape.IsSameAs("Carre") || selectedShape.IsSameAs("Rectangle"))
    {
        Rectangle r(m_mousePoint.x - size / 2, m_mousePoint.y - size / 2, size, size, "", color, colorBorder, borderSize, filled);
        PaintRect(dc, &r);
    }
    else if(selectedShape.IsSameAs("Rectangle"))
    {
        Rectangle r(m_mousePoint.x, m_mousePoint.y, size, size + size/ 3, "", color,colorBorder, borderSize, filled);
        PaintRect(dc, &r);
    }
    else if (selectedShape.IsSameAs("Cercle"))
    {
        Circle c(m_mousePoint.x, m_mousePoint.y, size, "", color, colorBorder, borderSize, filled);

        PaintCircle(dc, &c);
    }
}
