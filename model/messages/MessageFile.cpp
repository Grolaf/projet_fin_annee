#include "MessageFile.hpp"
#include "Message.hpp"
#include "MessagesTypes.hpp"

MessageFile::MessageFile(MessagesTypes t, wxString &fileName): Message(t), m_fileName(fileName)
{}

void MessageFile::setFileName(wxString &filename)
{
    m_fileName = filename;
}
