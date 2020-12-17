cmake_minimum_required(VERSION 3.0.0)
project(PhysicsEngine VERSION 0.1.0)

add_subdirectory(googletest)

add_library(src_files SHARED
    src/core.cpp
)

#add_executable(testDriver 
#    src/main.cpp
#)

add_executable(unit_test
    test/unit_test.cpp
)

#target_link_libraries(testDriver src_files)
target_link_libraries(unit_test src_files gtest)