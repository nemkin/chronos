cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(chronos)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

find_package(ortools CONFIG REQUIRED)

find_package(Qt5Core)
find_package(Qt5Gui)

set(QT_LIBRARIES
    Qt5::Core
    Qt5::Gui
)   

message(${QT_LIBRARIES})

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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

include_directories(${QT_INCLUDES})
include_directories(${PROJECT_SOURCE_DIR})

set(MODEL_SOURCES
${PROJECT_SOURCE_DIR}/model/generated/database/database.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/class.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/class_type.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/course.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/department.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/faculty_member.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/license.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/location.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/room.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/timeslot.cpp
${PROJECT_SOURCE_DIR}/model/generated/entities/year.cpp
)

set(SERVER_SOURCES
${PROJECT_SOURCE_DIR}/server/main.cpp
${PROJECT_SOURCE_DIR}/server/database_manual.cpp
${PROJECT_SOURCE_DIR}/server/proposal.cpp
${PROJECT_SOURCE_DIR}/server/timetable.cpp
)

set(RESOURCES
${PROJECT_SOURCE_DIR}/client/resources.qrc
)

set(CLIENT_SOURCES
${PROJECT_SOURCE_DIR}/client/main.cpp
)

add_executable(server ${MODEL_SOURCES} ${SERVER_SOURCES})
target_link_libraries(server ${PQXX_LIB} ${PQ_LIB})
target_link_libraries(server ortools::ortools)

add_executable(client ${MODEL_SOURCES} ${CLIENT_SOURCES} ${RESOURCES})
target_link_libraries(client ${PQXX_LIB} ${PQ_LIB})
target_link_libraries(client ${QT_LIBRARIES})

