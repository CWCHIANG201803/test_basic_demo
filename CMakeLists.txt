cmake_minimum_required(VERSION 3.0.0)
project(test_basic_demo VERSION 0.1.0 LANGUAGES C CXX)



add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(src)
include(CTest)
enable_testing()

add_executable(test_basic_demo main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

