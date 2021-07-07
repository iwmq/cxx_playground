#include<chrono>
#include<functional>
#include<iostream>

#include<boost/asio.hpp>

void timer_cb(const boost::system::error_code& /*e*/,
    boost::asio::steady_timer* t, int* count)
{
    if(*count < 5)
    {
        std::cout << "Calling timer_cb: " << *count << "!" << std::endl;
        ++(*count);
        t->expires_at(t->expiry() + std::chrono::seconds(1));
        t->async_wait(std::bind(timer_cb, std::placeholders::_1, t, count));
    }
    else{
        std::cout << "Finishing calling timer_cb!" << std::endl;
    }
}

int main(int argc, char** argv)
{
    boost::asio::io_context io;

    int count = 0;
    boost::asio::steady_timer t(io, std::chrono::seconds(1));
    t.async_wait(std::bind(timer_cb, std::placeholders::_1, &t, &count));
    std::cout << "You just called a synchronous timer!" << std::endl;

    io.run();
    std::cout << "Final count is " << count << std::endl;

    return 0;
}