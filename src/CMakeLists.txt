cmake_minimum_required(VERSION 3.24)
project(libmhl)

set(CMAKE_CXX_STANDARD 17)

add_library(libmhl Clip.cpp Clip.h Mhl.cpp Mhl.h)
target_link_libraries(libmhl pugixml)