cmake_minimum_required(VERSION 3.24)
project(libmhl)

set(CMAKE_CXX_STANDARD 17)

add_library(libmhl
        HashList.cpp
        HashList.h
        Utils.cpp
        Utils.h
        IgnoreSpec.cpp
        IgnoreSpec.h)
target_link_libraries(libmhl pugixml)