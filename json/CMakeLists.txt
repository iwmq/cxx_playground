# Setup JSON for modern c++
if(WIN32)
    set(JSON_INCLUDE_DIR "C:/dev/json_for_modern_cxx/include")
endif()


include_directories(
    ${JSON_INCLUDE_DIR}
)

add_executable(json_demo json_demo.cpp)