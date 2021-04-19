cmake_minimum_required(VERSION 3.0)

project(cxx_demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY output)
# https://cmake.org/cmake/help/latest/prop_tgt/RUNTIME_OUTPUT_DIRECTORY.html


include_directories(include)

add_executable(greet src/greet.cpp)
add_executable(vector_demo src/vector_demo.cpp)
add_executable(map_demo src/map_demo.cpp)
# add_executable(boost_bind_demo src/boost_bind_demo.cpp)
target_compile_features(vector_demo PRIVATE cxx_long_long_type)
