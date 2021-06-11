#ifndef __MYCONTROLPANEL__
#define __MYCONTROLPANEL__

#include "wx/wxprec.h"
#include <wx/clrpicker.h>
#include <wx/textctrl.h>

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "Observed.hpp"

#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

//------------------------------------------------------------------------
class MyControlPanel: public wxPanel, public Observed
                    //------------------------------------------------------------------------
{
public:
  MyControlPanel( wxWindow *parent ) ;
  int GetShapeSize() const{return m_shapeSize->GetValue() ;} ;
  int GetBorderSize() const{return m_borderSize->GetValue() ;} ;
  bool GetCheckBoxTextValue()const {return m_checkBox->GetValue() ;} ;
  bool GetCheckBoxFillShapeValue()const {return m_fillShape->GetValue() ;} ;
  bool GetCheckBoxPrevisualizeValue()const {return m_previsualizeShape->GetValue() ;} ;
  wxString GetSelectedShape() const{ return m_drawTools->GetStringSelection();};
  wxColour GetShapeColour()const {return m_shapeColor->GetColour();};
    wxColour GetBorderColour()const {return m_borderColor->GetColour();};

    void OnSlider(wxScrollEvent &event) ;

    void OnCheckBox(wxCommandEvent &event) ;
    void OnCheckBoxPrevisualize(wxCommandEvent &event) ;
    void OnSelection(wxCommandEvent &event);

    void OnButton(wxCommandEvent &event) ;

    void OnColourChanged(wxColourPickerEvent& evt);


private:

    //wxBoxSizer *sizer1;

    // Option Default ----------------------

    wxSlider* m_shapeSize ;
    wxSlider* m_borderSize;
    wxCheckBox* m_checkBox ;
    wxCheckBox* m_fillShape ;
    wxCheckBox* m_previsualizeShape ;
    wxCheckBox* m_selection ;
    wxStaticText* text1;
    wxButton *m_button ;

    // Option Color picker  ----------------------
    wxColourPickerCtrl* m_shapeColor;
    wxColourPickerCtrl* m_borderColor;
    wxTextCtrl *m_textCtrl;


    // Option DrawTools:
    wxRadioBox *m_drawTools;
};

#endif