# Setup Eigen
if(WIN32)
    set(EIGEN3_ROOT "C:/Apps/eigen/eigen-3.4.0/build")
endif()

find_package(Eigen3 REQUIRED NO_MODULE)
if (Eigen3_FOUND)
    message("Found Eigen3")
endif()

link_libraries(Eigen3::Eigen)

add_executable(test test.cpp)