# This is needed if using MinGW on Windows
if(MINGW)
  link_libraries(ws2_32)
endif()

add_executable(asio_timer_sync asio_timer_sync.cpp)
add_executable(asio_timer_async asio_timer_async.cpp)
add_executable(asio_timer_function asio_timer_function.cpp)
add_executable(asio_timer_member_function asio_timer_member_function.cpp)
add_executable(asio_timer_concurrent asio_timer_concurrent.cpp)
add_executable(asio_daytime_client asio_daytime_client.cpp)