cmake_minimum_required(VERSION 3.24)
project(libmhl)
enable_testing()
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test/ctest)
