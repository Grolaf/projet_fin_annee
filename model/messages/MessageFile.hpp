#ifndef __MESSAGEFILE_HPP_INCLUDED__
#define __MESSAGEFILE_HPP_INCLUDED__

#include "MessagesTypes.hpp"


#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "Message.hpp"

class MessageFile : public Message
{
    private :
        std::string m_fileName ;

    public: 
        MessageFile(MessagesTypes t, std::string fileName);
        ~MessageFile();

        // Setters
        void setFileName(std::string fileName);

        // Getters
        std::string getFileName() const;
};


#endif
