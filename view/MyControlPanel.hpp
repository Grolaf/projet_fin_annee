#ifndef __MYCONTROLPANEL__
#define __MYCONTROLPANEL__

#include "wx/wxprec.h"
#include <wx/clrpicker.h>
#include <wx/textctrl.h>

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
                    //------------------------------------------------------------------------
{
public:
  MyControlPanel( wxWindow *parent ) ;
  int GetSliderValue() {return m_slider->GetValue() ;} ;
  bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;

    void OnSlider(wxScrollEvent &event) ;

    void OnCheckBox(wxCommandEvent &event) ;

    void OnButton(wxCommandEvent &event) ;

    void OnColourChanged(wxColourPickerEvent& evt);



private:

    //wxBoxSizer *sizer1;
    wxSlider* m_slider ;
    wxCheckBox* m_checkBox ;
    wxStaticText* text1;
    wxButton *m_button ;
    wxColourPickerCtrl* m_colourPicker;

    wxTextCtrl *m_textCtrl;
};

#endif