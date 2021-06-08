#ifndef __MESSAGES_HPP_INCLUDED__
#define __MESSAGES_HPP_INCLUDED__


#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include "wx/wxprec.h"

#include "MessagesTypes.hpp"

class Message
{
    protected :
        MessagesTypes m_type;

    public : 
        Message(const MessagesTypes t);
        virtual ~Message();

        // Getters
        MessagesTypes getType() const;

        // Setters
        void setMessageType(const MessagesTypes t);
};

#endif
