#ifndef __MESSAGEFILE_HPP_INCLUDED__
#define __MESSAGEFILE_HPP_INCLUDED__

#include <string>

#include "Message.hpp"
#include "MessagesTypes.hpp"

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
