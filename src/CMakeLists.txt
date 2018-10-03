cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(cryptex)

find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Sql)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5SerialPort)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
find_package(Qt5Test)

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations -std=c++11")

include_directories(${QT_INCLUDES})
MESSAGE("HEYOOO")
MESSAGE("${QT_INCLUDES}")
MESSAGE("HEYOOO")

add_executable(server server/main.cpp)
target_link_libraries(server
    Qt5::Core
    Qt5::Network
    Qt5::Sql
    Qt5::Widgets
    Qt5::Gui
    Qt5::SerialPort
    Qt5::Multimedia
    Qt5::MultimediaWidgets
    Qt5::Test
)

