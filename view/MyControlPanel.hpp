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
  int GetSliderValue() const{return m_slider->GetValue() ;} ;
  bool GetCheckBoxTextValue()const {return m_checkBox->GetValue() ;} ;
  bool GetCheckBoxFillShapeValue()const {return m_fillShape->GetValue() ;} ;
  bool GetCheckBoxPrevisualizeValue()const {return m_previsualizeShape->GetValue() ;} ;
  wxString GetSelectedShape() const{ return m_drawTools->GetStringSelection();};
  wxColour GetColour()const {return m_colourPicker->GetColour();};

    void OnSlider(wxScrollEvent &event) ;

    void OnCheckBox(wxCommandEvent &event) ;
    void OnCheckBoxPrevisualize(wxCommandEvent &event) ;

    void OnButton(wxCommandEvent &event) ;

    void OnColourChanged(wxColourPickerEvent& evt);


private:

    //wxBoxSizer *sizer1;

    // Option Default ----------------------

    wxSlider* m_slider ;
    wxCheckBox* m_checkBox ;
    wxCheckBox* m_fillShape ;
    wxCheckBox* m_previsualizeShape ;
    wxStaticText* text1;
    wxButton *m_button ;

    // Option Color picker  ----------------------
    wxColourPickerCtrl* m_colourPicker;
    wxTextCtrl *m_textCtrl;


    // Option DrawTools:
    wxRadioBox *m_drawTools;
};

#endif