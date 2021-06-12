#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500
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
    ID_SLIDER1,
    ID_SLIDER2,
    ID_CHECKBOX1,
    ID_CHECKBOX2,
    ID_CHECKBOX3,
    ID_RADIOBOX,
    ID_CLPICKER1,
    ID_CLPICKER2,
    ID_CHECKBOX4
};
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent), Observed()
  //------------------------------------------------------------------------
  // In this constructor, create the controls and associate each of them (bind) a method
{
    // Position and size variable ::
        int w, h, y ;
    wxString labelradio ="Choix de formes :";
    SetBackgroundColour(*wxLIGHT_GREY) ;

    // Default size fonction

  GetParent()->GetSize(&w,&h) ;
  SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;

  // View DrawTools ::

    y = WIDGET_Y0 ;
    wxString tabChoix[6] = {"Carre","Rectangle","Cercle","Ellipse","Ligne","Polygone"};
    m_drawTools = new wxRadioBox(this, ID_RADIOBOX, labelradio, wxPoint(10,y), wxDefaultSize,6,tabChoix,0,wxRA_SPECIFY_ROWS);
    m_drawTools->SetForegroundColour(wxColor(250,250,250));


    // Bind DrawTools ::


        // Other Tools
  
  y+= WIDGET_Y_STEP + WIDGET_Y_SECURE;
  m_text1 = new wxStaticText(this, wxID_ANY, wxT("Taille de la forme"), wxPoint(10, y)) ;
  m_text1->SetForegroundColour(wxColor(250,250,250));
  
  y+= WIDGET_Y_STEP ;
  m_shapeSize = new wxSlider(this, ID_SLIDER1, 10, 2, 450, wxPoint(10, y), wxSize(100,20),wxSL_MIN_MAX_LABELS) ;
     Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

  y+= WIDGET_Y_STEP;

  m_text2 = new wxStaticText(this, wxID_ANY, wxT("Taille de la bordure"), wxPoint(10, y)) ;
  m_text2->SetForegroundColour(wxColor(250,250,250));

  y+= WIDGET_Y_STEP ;
  m_borderSize = new wxSlider(this, ID_SLIDER2, 10, 2, 45, wxPoint(10, y), wxSize(100,20),wxSL_MIN_MAX_LABELS ) ;
    m_borderSize->SetForegroundColour(wxColor(250,250,250));
  Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER2) ;

  y+= WIDGET_Y_STEP  ;

    m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Montrer coordonnees", wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

    y+= WIDGET_Y_STEP;
    m_fillShape = new wxCheckBox(this, ID_CHECKBOX2,"Forme pleine", wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX2) ;

    y+= WIDGET_Y_STEP ;
    m_previsualizeShape = new wxCheckBox(this, ID_CHECKBOX3, "Previsualiser la forme", wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBoxPrevisualize, this, ID_CHECKBOX3) ;

    y+= WIDGET_Y_STEP ;
    m_moveShape = new wxCheckBox(this, ID_CHECKBOX4, "Selection", wxPoint(10, y), wxSize(100,20)) ;
        Bind(wxEVT_CHECKBOX, &MyControlPanel::OnSelection, this, ID_CHECKBOX4) ;



    y+= WIDGET_Y_STEP;

    m_text3 = new wxStaticText(this, wxID_ANY, wxT("Couleur de la forme"), wxPoint(10, y)) ;
    m_text3->SetForegroundColour(wxColor(250,250,250));
    y+= 25 ;
      // Create a wxColourPickerCtrl control
     m_shapeColor = new wxColourPickerCtrl(this, ID_CLPICKER1 , wxColour(255, 0, 0), wxPoint(10, y), wxSize(100, 20) );
   Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColourChanged, this, ID_CLPICKER1) ;

    y+= WIDGET_Y_STEP;

    m_text4 = new wxStaticText(this, wxID_ANY, wxT("Couleur de la bordure"), wxPoint(10, y)) ;
    m_text4->SetForegroundColour(wxColor(250,250,250));
    y+= 25 ;
    m_borderColor = new wxColourPickerCtrl(this, ID_CLPICKER2 , wxColour(255, 0, 0), wxPoint(10, y), wxSize(100, 20) );
    Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnColourChanged, this, ID_CLPICKER2) ;

}

MyControlPanel::~MyControlPanel() {

    delete m_drawTools;
    delete m_text1;
    delete m_text2;
    delete m_text3;
    delete m_text4;
    delete m_shapeSize;
    delete m_borderSize;
    delete m_checkBox;
    delete m_fillShape;
    delete m_previsualizeShape;
    delete m_moveShape;
    delete m_shapeColor;
    delete m_borderColor;
}
//------------------------------------------------------------------------
    void MyControlPanel::OnColourChanged(wxColourPickerEvent &evt)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*) GetParent();
    frame->RefreshDrawing();
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
  Message* m  = new Message(REFRESH);
  notifyObserver(m);
  delete m;
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBoxPrevisualize(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    Message* m = new Message(PREVISUALIZE);
    notifyObserver(m);
    delete m;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSelection(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    Message* m = new Message(SELECTION);
    notifyObserver(m);
    delete m;
}
