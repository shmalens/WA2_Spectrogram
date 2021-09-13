cmake_minimum_required(VERSION 3.8)
project(WAV2_Spectrogram)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Werror -Wpedantic -ggdb3")
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -ggdb3")

set(EXECUTABLE_NAME main)

add_executable(EXECUTABLE_NAME project/main.cpp)

include_directories(project/include)

add_library(MMFile STATIC project/src/MMFile.cpp)

target_link_libraries(EXECUTABLE_NAME MMFile)

option(TEST "Build tests" OFF)
if (TEST)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    # Create binaries of tests
    add_executable(mmfile_tests tests/MMFileTests.cpp)
    target_link_libraries(mmfile_tests gtest_main)
    target_link_libraries(mmfile_tests MMFile)

    # Needs to discover cmake test system how to find
    # my tests binaries and use it
    include(GoogleTest)
    gtest_discover_tests(mmfile_tests)
endif ()