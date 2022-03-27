cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME Asteroids)
set(PROJECT_TESTS_NAME Asteroids_tests)

project(${PROJECT_NAME} VERSION 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(submodules/googletest/googletest/include/gtest)
include_directories(submodules/SDL/include)
include_directories(submodules/SDL_image)

add_subdirectory(submodules/googletest)
add_subdirectory(submodules/SDL)
add_subdirectory(submodules/SDL_image)

include_directories(src)
add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
