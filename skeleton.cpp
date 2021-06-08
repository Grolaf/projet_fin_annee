// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "view/MyApp.hpp"
#include "view/MyFrame.hpp"
#include "view/MyDrawingPanel.hpp"
#include "view/MyControlPanel.hpp"

#include "model/Dao.hpp"
#include "model/messages/MessageFile.hpp"
#include "model/messages/Message.hpp"
#include "model/messages/MessagesTypes.hpp"

#include "controler/controler.hpp"
#include "controler/Observer.hpp"


IMPLEMENT_APP(MyApp) // macro that contains the main() function