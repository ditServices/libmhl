cmake_minimum_required(VERSION 3.24)
project(libmhl)

set(CMAKE_CXX_STANDARD 17)

add_library(libmhl
        Utils.cpp
        Utils.h
        IgnoreSpec.cpp
        IgnoreSpec.h
        Chain.cpp
        Chain.h
        ChainFile.cpp
        ChainFile.h
        ChainGeneration.cpp
        ChainGeneration.h
        History.cpp
        History.h
        HashList.cpp
        HashList.h)
target_link_libraries(libmhl pugixml)