cmake_minimum_required(VERSION 3.0)

project(cxx_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY output)
# https://cmake.org/cmake/help/latest/prop_tgt/RUNTIME_OUTPUT_DIRECTORY.html

# Introduce modules
include(CMakePrintHelpers)

# Setup Boost
if(WIN32)
    set(BOOST_ROOT "c:/apps/boost/devel")
    set(BOOST_LIBRARYDIR "c:/apps/boost/devel/lib")
    set(BOOST_INCLUDEDIR "c:/apps/boost/devel/include")
endif()
find_package(Boost 1.76.0 COMPONENTS program_options)
if(Boost_FOUND)
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)

    message("Find Boost in " ${BOOST_INCLUDEDIR})
    cmake_print_variables(BOOST_INCLUDEDIR)
endif()
# END: Setup Boost

include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)

add_executable(greet src/greet.cpp)
add_executable(vector_demo src/vector_demo.cpp)
add_executable(map_demo src/map_demo.cpp)
add_executable(boost_bind_demo src/boost_bind_demo.cpp)
add_executable(thread_demo src/thread_demo.cpp)
target_compile_features(vector_demo PRIVATE cxx_long_long_type)
# NOTE: Beware white spaces for separating items,
# and no white space within an item
target_compile_options(vector_demo PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# For directory-wide
# https://cmake.org/cmake/help/latest/command/add_compile_options.html#command:add_compile_options
# if (MSVC)
#     # warning level 4 and all warnings as errors
#     add_compile_options(/W4 /WX)
# else()
#     # lots of warnings and all warnings as errors
#     add_compile_options(-Wall -Wextra -pedantic -Werror)
# endif()