#ifndef __MESSAGEFILE_HPP_INCLUDED__
#define __MESSAGEFILE_HPP_INCLUDED__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "Message.hpp"
#include "MessagesTypes.hpp"

class MessageFile : public Message
{
    
    private :
        wxString m_fileName;

    public : 

        MessageFile(MessagesTypes t, wxString &fileName);
        virtual ~MessageFile() = default;

        void setFileName(wxString &fileName);
};

#endif
