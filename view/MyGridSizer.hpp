//
// Created by lebagouv on 09/06/2021.
//

#include <wx/wx.h>

class GridSizer : public wxFrame
{
public:
    GridSizer(const wxString& title);

    wxBoxSizer *sizer;
    wxGridSizer *gs;
    wxTextCtrl *display;

};