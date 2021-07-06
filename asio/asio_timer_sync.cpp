#include<chrono>
#include<ctime>
#include<iostream>
#include<boost/asio.hpp>
#pragma comment(lib, "ws2_32")

int main(int argc, char** argv)
{
    boost::asio::io_context io;

    auto start = std::chrono::system_clock::now();
    // Define a synchronous timer
    boost::asio::steady_timer t(io, std::chrono::seconds(5));
    t.wait();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "You just called a synchronous timer!" << std::endl;
    std::cout << "Actual time used: " << diff.count() << " seconds!" << std::endl;

    return 0;
}