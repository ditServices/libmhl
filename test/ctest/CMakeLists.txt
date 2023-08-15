cmake_minimum_required(VERSION 3.24)
project(libmhl)

set(CMAKE_CXX_STANDARD 17)

set(TEST_CHAIN_PATH "../test_mhl/A002R2EC/ascmhl/ascmhl_chain.xml")
file(COPY ${TEST_CHAIN_PATH} DESTINATION "resources")

include_directories(${libmhl_SOURCE_DIR})
include_directories(${libmhl_LIB_DIR})

add_executable(ctest_ignorespec_null_test ctest_ignorespec_null.cpp)
target_link_libraries(ctest_ignorespec_null_test libmhl)
add_test(ctest_ignorespec_null_result ctest_ignorespec_null_test)

add_executable(ctest_currenttime_test ctest_currenttime_test.cpp)
target_link_libraries(ctest_currenttime_test libmhl)
add_test(ctest_currenttime_test_result ctest_currenttime_test)

add_executable(ctest_host_test ctest_host_test.cpp)
target_link_libraries(ctest_host_test libmhl)
add_test(ctest_host_test_result ctest_host_test)

add_executable(ctest_chainfile_test ctest_chainfile_test.cpp)
target_link_libraries(ctest_chainfile_test libmhl pugixml)
add_test(ctest_chainfile_test_result ctest_chainfile_test)