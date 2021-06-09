#include "MyGridSizer.hpp"

GridSizer::GridSizer(const wxString& title)
        : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(270, 220))
        {

            sizer = new wxBoxSizer(wxVERTICAL);

            gs = new wxGridSizer(4, 4, 3, 3);

            gs->Add(new wxButton(this, -1, wxT("Cls")), 0, wxEXPAND);
            gs->Add(new wxButton(this, -1, wxT("Bck")), 0, wxEXPAND);
            gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
            gs->Add(new wxButton(this, -1, wxT("Close")), 0, wxEXPAND);

            sizer->Add(gs, 1, wxEXPAND);
            SetSizer(sizer);
            SetMinSize(wxSize(270, 220));

            Centre();

            }