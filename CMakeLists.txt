cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(skeleton skeleton.cpp 
                controler/Observer.hpp 
                controler/controler.cpp controler/controler.hpp 
                view/Observed.cpp view/Observed.hpp)
target_link_libraries(skeleton ${wxWidgets_LIBRARIES})
