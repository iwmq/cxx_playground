#include<chrono>
#include<ctime>
#include<iostream>
#include<boost/asio.hpp>

void timer_cb(const boost::system::error_code& /*e*/)
{
    std::cout << "Calling timer_cb!" << std::endl;
}

int main(int argc, char** argv)
{
    boost::asio::io_context io;

    auto start = std::chrono::system_clock::now();
    // Define an asynchronous timer
    boost::asio::steady_timer t(io, std::chrono::seconds(5));
    t.async_wait(timer_cb);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "You just called a synchronous timer!" << std::endl;
    std::cout << "Actual time used: " << diff.count() << " seconds!" << std::endl;

    io.run();

    return 0;
}