#include "MyFrame.hpp"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "../model/messages/MessageFile.hpp"
#include "MyMenu.hpp"

#endif

#include "../constants.hpp"
#include "MyDrawingPanel.hpp"


// Define constant of app


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame((wxFrame *)NULL, -1, title, pos, size), Observed()

  // The constructor of the main frame that creates the menu stuffs and the 2 panels
{
    // create menu that will contain menu itemsfilemenu = new MyMenu();
    filemenu = new MyMenu(this);

  wxMenuBar *menuBar = new wxMenuBar();
    menuBar->SetBackgroundColour(wxColor(221, 223, 231));

    menuBar->Append(filemenu, wxT("&File"));

     Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
    Bind(wxEVT_SIZE, &MyFrame::OnSize, this);
    Bind(wxEVT_CHAR_HOOK, &MyFrame::OnKeyDown, this);

     SetMenuBar( menuBar );

  // ---------------------



  // create the panel that will contain the controls
    m_controlPanel = new MyControlPanel(this);

    m_controlPanel->SetBackgroundColour(wxColor(105,117,157));

    // create the panel that will display the graphics
    m_drawingPanel = new MyDrawingPanel(this);






    CreateStatusBar() ;

   ;
  Centre() ; // Guess what it does ;-)
}

//------------------------------------------------------------------------
void MyFrame::RefreshCoord(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
    wxString coordinates ;
    coordinates.sprintf(wxT("(%d,%d)"),m_drawingPanel->getMouse().x,m_drawingPanel->getMouse().y);
    SetStatusText(coordinates);
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
  wxMessageBox(wxT("How to .. \n\n- CTRL-C = copy\n- CTRL-V = paste\n - CTRL-Z = undo (do not work for deleted shapes)\n- CTRL-Y = redo (do not work for deleted shapes)\n\n Antoine Barrier\n Vincent Le Bagousse"),
               APP_NAME, wxOK | wxICON_INFORMATION ) ;
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
  std::string filename = std::string(wxSaveFileSelector("Save file as", "*.bin", "data").c_str());
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

void MyFrame::RefreshDrawing()
{
    Message* m = new Message(REFRESH);
    notifyObserver(m);
    delete m;
}
