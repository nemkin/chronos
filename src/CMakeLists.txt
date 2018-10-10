cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(chronos)

find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Sql)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5SerialPort)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
find_package(Qt5Test)

set(QT_LIBRARIES
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

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations -std=c++11")

include_directories(${QT_INCLUDES})
include_directories(${PROJECT_SOURCE_DIR})

set(SERVER_SOURCES
${PROJECT_SOURCE_DIR}/server/main.cpp
${PROJECT_SOURCE_DIR}/server/server.cpp
${PROJECT_SOURCE_DIR}/server/service/service.cpp
${PROJECT_SOURCE_DIR}/common/entities/department.cpp
${PROJECT_SOURCE_DIR}/server/database/database.cpp
)

set(CLIENT_SOURCES
${PROJECT_SOURCE_DIR}/client/main.cpp
${PROJECT_SOURCE_DIR}/client/client.cpp
)

add_executable(server ${SERVER_SOURCES})
target_link_libraries(server ${QT_LIBRARIES})

add_executable(client ${CLIENT_SOURCES})
target_link_libraries(client ${QT_LIBRARIES})

