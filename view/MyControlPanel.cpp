#define APPLICATION_WIDTH	700
#define APPLICATION_HEIGHT	600
#define APP_NAME "Svex Editors v1.0"
#define WIDGET_PANEL_WIDTH	250
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
#define WIDGET_Y_SECURE		120

#include "MyControlPanel.hpp"
#include "MyFrame.hpp"

#include <wx/panel.h>

enum
{
    ID_QUIT = 1,
    ID_ABOUT,
    ID_LOAD,
    ID_SAVE,
    ID_BUTTON1,
    ID_SLIDER1,
    ID_CHECKBOX1,
    ID_RADIOBOX,
    ID_CLPICKER1
};


MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
  //------------------------------------------------------------------------
  // In this constructor, create the controls and associate each of them (bind) a method
{
    // Position and size variable ::
        int w, h, y ,xx;
    wxString labelradio ="Choix de formes :";
    SetBackgroundColour(*wxLIGHT_GREY) ;




    // Default size fonction

  GetParent()->GetSize(&w,&h) ;
  SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;

  // View DrawTools ::

    y = WIDGET_Y0 ;
    wxString tabChoix[6] = {"carre","rectangle","cercle","ellipse","ligne","polygone"};
    drawTools = new wxRadioBox(this, ID_RADIOBOX, labelradio, wxPoint(10,y), wxDefaultSize,6,tabChoix,0,wxRA_SPECIFY_ROWS);
    drawTools->SetForegroundColour(wxColor(250,250,250));


    // Bind DrawTools ::



        // Other Tools
  
  y+= WIDGET_Y_STEP + WIDGET_Y_SECURE;
  text1 = new wxStaticText(this, wxID_ANY, wxT("Taille"), wxPoint(10, y)) ;
    text1->SetForegroundColour(wxColor(250,250,250));
  
  y+= 15 ;
  m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
  Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;
  
  y+= WIDGET_Y_STEP ;
    m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Montrer coordonnées", wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;



    y+= WIDGET_Y_STEP;

      // Create a wxColourPickerCtrl control
    wxColourPickerCtrl* colourPickerCtrl = new wxColourPickerCtrl(this,ID_CLPICKER1 , wxColour(255,0,0), wxPoint(10, y), wxSize(100,20) );
   Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColourChanged, this, ID_CHECKBOX1) ;

}


//------------------------------------------------------------------------
    void MyControlPanel::OnColourChanged(wxColourPickerEvent &evt)
//------------------------------------------------------------------------
{
     m_textCtrl->SetForegroundColour(GetColour());
     m_textCtrl->Refresh();

    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;

    }

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
  //------------------------------------------------------------------------
{
  //	char* s = GetCString() ;
  //	wxMessageBox(wxString::FromAscii(s)) ; // call a C function located in the sample.cp module
  //	free(s) ;
  wxMessageBox(wxT("You just pressed the button!")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
  //------------------------------------------------------------------------
{
  MyFrame* frame = (MyFrame*)GetParent() ;
  frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
  //------------------------------------------------------------------------
{
  MyFrame* frame = (MyFrame*)GetParent() ;
  frame->RefreshDrawing() ;	// update the drawing panel
}

