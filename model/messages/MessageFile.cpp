#include "MessageFile.hpp"
#include "Message.hpp"
#include "MessagesTypes.hpp"
#include <string.h>

using namespace std;

MessageFile::MessageFile(MessagesTypes t, string fileName): Message(t), m_fileName(fileName)
{}

void MessageFile::setFileName(string fileName)
{
    m_fileName = fileName;
}

string MessageFile::getFileName() const
{
    return m_fileName;
}

MessageFile::~MessageFile(){}
