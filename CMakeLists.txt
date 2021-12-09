cmake_minimum_required(VERSION 3.10)

project(cxx_demo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY output)
# https://cmake.org/cmake/help/latest/prop_tgt/RUNTIME_OUTPUT_DIRECTORY.html

# Introduce modules
include(CMakePrintHelpers)

# Setup Boost
if(WIN32)
    set(BOOST_ROOT "c:/dev/boost/devel")
    set(BOOST_LIBRARY_DIR "c:/dev/boost/devel/lib")
    set(BOOST_INCLUDE_DIR "c:/dev/boost/devel/include")
endif()
find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)

    message("Find Boost in " ${BOOST_INCLUDEDIR})
    cmake_print_variables(BOOST_INCLUDE_DIR)
endif()
# END: Setup Boost

# Setup fmtlib
if(WIN32)
    set(fmt_DIR "c:/dev/fmt/fmt-8.0.1/build")
    set(fmt_LIBRARYDIR "c:/dev/fmt/devel/lib")
    set(fmt_INCLUDEDIR "c:/dev/fmt/devel/include")
endif()
find_package(fmt 8.0.1 NO_MODULE REQUIRED)
if(fmt_FOUND)
    message("Find fmt in " ${fmt_INCLUDEDIR})
    cmake_print_variables(fmt_INCLUDEDIR)
endif()
# END: Setup fmtlib

include_directories(
    ${Boost_INCLUDE_DIRS}
    include()
)
# include_directories(include)

add_executable(greet src/greet.cpp)
add_executable(variadic src/variadic.cpp)

add_executable(fmt_demo src/fmt_demo.cpp)
target_include_directories(fmt_demo
    PRIVATE ${fmt_INCLUDEDIR}
)
target_link_libraries(fmt_demo PRIVATE fmt::fmt)

add_executable(vector_demo src/vector_demo.cpp)
add_executable(map_demo src/map_demo.cpp)
add_executable(vector_if_demo src/vector_if_demo.cpp)
add_executable(ranges_demo src/ranges_demo.cpp)

add_executable(boost_bind_demo src/boost_bind_demo.cpp)
add_executable(std_bind_demo src/std_bind_demo.cpp)

add_executable(thread_demo src/thread_demo.cpp)
add_executable(jthread_demo src/jthread_demo.cpp)
add_executable(mutex_demo src/mutex_demo.cpp)

add_executable(smart_pointers_demo src/smart_pointers_demo.cpp)
add_executable(double_pointer_demo
    src/double_pointer_demo.c
    src/pointer_utilities.c
)
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

add_subdirectory(asio)
add_subdirectory(spirit)
add_subdirectory(eigen)
add_subdirectory(json)
add_subdirectory(taskflow)