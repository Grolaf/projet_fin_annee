#include "myFrame.hpp"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif



// Define constant of app

#define APPLICATION_WIDTH	700
#define APPLICATION_HEIGHT	600
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
#define APP_NAME "Svex Editors v1.0"

enum
{
    ID_QUIT = 1,
    ID_ABOUT,
    ID_LOAD,
    ID_SAVE,
    ID_BUTTON1,
    ID_SLIDER1,
    ID_CHECKBOX1
};

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame((wxFrame *)NULL, -1, title, pos, size), Observed()

  // The constructor of the main frame that creates the menu stuffs and the 2 panels
{
  wxMenu *fileMenu = new wxMenu();
  fileMenu->Append(ID_LOAD, wxT("&Open file..."));
  fileMenu->Append(ID_SAVE, wxT("&Save file..."));
  fileMenu->Append(ID_ABOUT, wxT("&About..."));
  fileMenu->AppendSeparator();
  fileMenu->Append(ID_QUIT, wxT("&Exit"));
  
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  
  Bind(wxEVT_MENU, &MyFrame::OnOpenFile, this, ID_LOAD);
  Bind(wxEVT_MENU, &MyFrame::OnSaveFile, this, ID_SAVE);
  Bind(wxEVT_MENU, &MyFrame::OnQuit, this, ID_QUIT);
  Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_ABOUT);
  Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
  Bind(wxEVT_SIZE, &MyFrame::OnSize, this);
  
  SetMenuBar( menuBar );
  
  // create the panel that will contain the controls
  m_controlPanel = new MyControlPanel(this);
  // create the panel that will display the graphics
  m_drawingPanel = new MyDrawingPanel(this);
  CreateStatusBar() ;
  SetStatusText(wxT("click in the right panel and tune the controls of the left panel. Visit the File menu!")) ;
  Centre() ; // Guess what it does ;-)
}

//------------------------------------------------------------------------
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
  //------------------------------------------------------------------------
{
  Close(true) ;
}

//------------------------------------------------------------------------
void MyFrame::OnClose(wxCloseEvent& event)
  //------------------------------------------------------------------------
{
  delete m_controlPanel ;
  delete m_drawingPanel ;
  event.Skip() ;
}

//------------------------------------------------------------------------
void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
  //------------------------------------------------------------------------
{
  wxMessageBox(wxT("How to .. \n\n- use 2 panels (one for controls, one for drawings)\n- manage basic events (so that controls impact drawings)\n\n... with wxWidgets (3.0.2)\n\nPascal Bertolino UGA - GIPSA-lab, Grenoble - France\npascal.bertolino@gipsa-lab.fr"),
               wxT(APP_NAME), wxOK | wxICON_INFORMATION ) ;
}

//------------------------------------------------------------------------
void MyFrame::OnOpenFile(wxCommandEvent& WXUNUSED(event) )
  //------------------------------------------------------------------------
{
  std::string filename = std::string(wxFileSelector("Select file").c_str());
  if ( !filename.empty() )
  {
    MessageFile* m = new MessageFile(OPEN_FILE, filename);
    notifyObserver(m);
    delete(m);
  }
}

//------------------------------------------------------------------------
void MyFrame::OnSaveFile(wxCommandEvent & WXUNUSED(event))
  //------------------------------------------------------------------------
{
  std::string filename = std::string(wxSaveFileSelector("Save file as", "*.txt", "data").c_str());
  if ( !filename.empty() )
  {
    MessageFile* m = new MessageFile(SAVE_FILE, filename);
    notifyObserver(m);
    delete(m);
  }
}

//------------------------------------------------------------------------
void MyFrame::OnSize(wxSizeEvent &event)
  //------------------------------------------------------------------------
  // Called when you resize the frame
{
  int w, h ;
  GetSize(&w,&h) ;	
  m_controlPanel->SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
  m_drawingPanel->SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
}