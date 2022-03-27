message("-- Processing tests/CMakeLists.txt")

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_TESTS_NAME} main.cpp)
target_link_libraries(${PROJECT_TESTS_NAME} PUBLIC gtest_main)