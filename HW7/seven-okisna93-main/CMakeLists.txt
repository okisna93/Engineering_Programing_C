cmake_minimum_required(VERSION 3.12)

# project's name
project(asgmtseven)

set(CMAKE_CXX_STANDARD 14)

# check for windows
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(SOURCE_FILES main.cpp)

#include_directories(src)

#add_subdirectory(src)
#add_subdirectory(../../EE553_c++_main/asgmtSeven/test)

add_executable(main_executable ${SOURCE_FILES})

target_link_libraries(main_executable)


