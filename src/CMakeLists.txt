cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(chronos)

set(PQXX /usr/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

# find_package(Qt5Core)
# find_package(Qt5Network)
# find_package(Qt5Sql)
# find_package(Qt5Widgets)
# find_package(Qt5Gui)
# find_package(Qt5SerialPort)
# find_package(Qt5Multimedia)
# find_package(Qt5MultimediaWidgets)
# find_package(Qt5Test)

# set(QT_LIBRARIES
#    Qt5::Core
#    Qt5::Network
#    Qt5::Sql
#    Qt5::Widgets
#    Qt5::Gui
#    Qt5::SerialPort
#    Qt5::Multimedia
#    Qt5::MultimediaWidgets
#    Qt5::Test
#)   

# Find includes in corresponding build directories
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
# set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
# set(CMAKE_AUTOUIC ON)

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

include_directories(${QT_INCLUDES})
include_directories(${PROJECT_SOURCE_DIR})

set(COMMON_SOURCES
${PROJECT_SOURCE_DIR}/common/database/database.cpp
${PROJECT_SOURCE_DIR}/common/entities/class.cpp
${PROJECT_SOURCE_DIR}/common/entities/class_type.cpp
${PROJECT_SOURCE_DIR}/common/entities/course.cpp
${PROJECT_SOURCE_DIR}/common/entities/department.cpp
${PROJECT_SOURCE_DIR}/common/entities/distance.cpp
${PROJECT_SOURCE_DIR}/common/entities/faculty_member.cpp
${PROJECT_SOURCE_DIR}/common/entities/grade.cpp
${PROJECT_SOURCE_DIR}/common/entities/license.cpp
${PROJECT_SOURCE_DIR}/common/entities/location.cpp
${PROJECT_SOURCE_DIR}/common/entities/major.cpp
${PROJECT_SOURCE_DIR}/common/entities/room.cpp
${PROJECT_SOURCE_DIR}/common/entities/room_type.cpp
${PROJECT_SOURCE_DIR}/common/entities/semester.cpp
${PROJECT_SOURCE_DIR}/common/entities/semester_type.cpp
)

set(SERVER_SOURCES
${PROJECT_SOURCE_DIR}/server/main.cpp
)

set(CLIENT_SOURCES
${PROJECT_SOURCE_DIR}/client/main.cpp
)

message(${PQXX_LIB})
message(${PQ_LIB})

add_executable(server ${COMMON_SOURCES} ${SERVER_SOURCES})
target_link_libraries(server ${PQXX_LIB} ${PQ_LIB})

# target_link_libraries(server ${QT_LIBRARIES})

add_executable(client ${COMMON_SOURCES} ${CLIENT_SOURCES})
target_link_libraries(client ${PQXX_LIB} ${PQ_LIB})

# target_link_libraries(client ${QT_LIBRARIES})

