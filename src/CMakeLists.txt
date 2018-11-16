cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(chronos)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

find_package(ortools CONFIG REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR}/model)

message(${MODEL_SOURCES})

set(SOURCES
${PROJECT_SOURCE_DIR}/server/main.cpp
${PROJECT_SOURCE_DIR}/server/database_manual.cpp
${PROJECT_SOURCE_DIR}/server/proposal.cpp
${PROJECT_SOURCE_DIR}/server/timetable.cpp
)

add_executable(server ${MODEL_SOURCES} ${SOURCES})
target_link_libraries(server ${PQXX_LIB} ${PQ_LIB})
target_link_libraries(server ortools::ortools)

