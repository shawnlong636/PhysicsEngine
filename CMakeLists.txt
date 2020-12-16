cmake_minimum_required(VERSION 3.0.0)
project(PhysicsEngine VERSION 0.1.0)

add_library(src_files SHARED
    src/core.cpp
)

add_executable(testDriver 
    src/main.cpp
)

target_link_libraries(testDriver src_files)