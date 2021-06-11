cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable

add_executable(skeleton skeleton.cpp view/MyApp.cpp view/MyDrawingPanel.cpp view/MyControlPanel.cpp view/MyFrame.cpp model/messages/Message.cpp model/messages/MessageFile.cpp model/Dao.cpp controler/controler.cpp  controler/Observer.cpp view/Observed.cpp model/shapes/circle.cpp model/shapes/triangle.cpp model/shapes/rectangle.cpp model/shapes/point.cpp model/draw.hpp constants.hpp model/shapes/shape.cpp model/draw.cpp model/MyModel.hpp model/MyModel.cpp model/messages/MessagePaint.hpp model/messages/MessagePaint.cpp model/MyRGB.cpp model/MyRGB.hpp view/MyMenu.cpp)


target_link_libraries(skeleton ${wxWidgets_LIBRARIES})
