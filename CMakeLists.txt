cmake_minimum_required(VERSION 3.24)
project(libmhl)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test/ctest)
