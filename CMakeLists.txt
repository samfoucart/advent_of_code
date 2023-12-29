cmake_minimum_required(VERSION 3.16.3)
project(day_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
    day_1_lib
    src/day_1.cpp
    include/day_1.h
)

add_library(
	day_2_lib
	src/day_2.cpp
	include/day_2.h
)

target_include_directories(
	day_2_lib
	PUBLIC
	include
)

target_include_directories(
    day_1_lib
    PUBLIC
    include
)

add_executable(
    day_1_main
    main/day_1_main.cpp
)

target_include_directories(
    day_1_main
    PUBLIC
    include
)

target_link_libraries(
    day_1_main
    day_1_lib
)

add_executable(
  day_1_test
  test/day_1_test.cpp
)

target_link_libraries(
  day_1_test
  GTest::gtest_main
  day_1_lib
)

target_include_directories(
    day_1_test
    PUBLIC
    include
)

include(GoogleTest)
gtest_discover_tests(day_1_test)
