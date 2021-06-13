

#include "MyMenu.hpp"
#include "MyFrame.hpp"
#include "../constants.hpp"


MyMenu::MyMenu(MyFrame* frame) : wxMenu(), m_myFrame(frame)
{
    this->Append(ID_LOAD, wxT("&Open file..."));
    this->Append(ID_SAVE, wxT("&Save file..."));
    this->Append(ID_ABOUT, wxT("&About..."));
    this->AppendSeparator();
    this->Append(ID_QUIT, wxT("&Exit"));

    Bind(wxEVT_MENU, &MyMenu::OnOpenFile, this, ID_LOAD);
    Bind(wxEVT_MENU, &MyMenu::OnSaveFile, this, ID_SAVE);
    Bind(wxEVT_MENU, &MyMenu::OnQuit, this, ID_QUIT);
    Bind(wxEVT_MENU, &MyMenu::OnAbout, this, ID_ABOUT);
}
void MyMenu::OnQuit(wxCommandEvent& event)
{
    m_myFrame->OnQuit(event);
}
void MyMenu::OnAbout(wxCommandEvent& event)
{
    m_myFrame->OnAbout(event);
}
void MyMenu::OnOpenFile(wxCommandEvent& event )
{
    m_myFrame->OnOpenFile(event);
}
void MyMenu::OnSaveFile(wxCommandEvent & event)
{
    m_myFrame->OnSaveFile(event);
}
