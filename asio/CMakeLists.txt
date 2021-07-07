# This is needed if using MinGW on Windows
if(MINGW)
  link_libraries(ws2_32)
endif()

add_executable(asio_timer_sync asio_timer_sync.cpp)
add_executable(asio_timer_async asio_timer_async.cpp)
add_executable(asio_timer_binding_function asio_timer_binding_function.cpp)