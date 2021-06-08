

#include "MyMenu.hpp"

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

MyMenu::MyMenu() : wxMenu()
{

    this->Append(ID_LOAD, wxT("&Open file..."));
    this->Append(ID_SAVE, wxT("&Save file..."));
    this->Append(ID_ABOUT, wxT("&About..."));
    this->AppendSeparator();
    this->Append(ID_QUIT, wxT("&Exit"));
}
