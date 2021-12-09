# Setup Taskflow
if(WIN32)
    set(TASKFLOW_ROOT "c:/dev/taskflow/devel")
    set(TASKFLOW_LIBRARY_DIR "c:/dev/taskflow/devel/lib")
    set(TASKFLOW_INCLUDE_DIR "c:/dev/taskflow/devel/include")
endif()
find_package(Taskflow 3.2.0 REQUIRED)
if(Taskflow_FOUND)
    message("Find taskflow")
    cmake_print_variables(TASKFLOW_INCLUDE_DIR)
endif()
# END: Setup Taskflow

include_directories(
    ${TASKFLOW_INCLUDE_DIR}
    include()
)

add_executable(taskflow_simple taskflow_simple.cpp)
