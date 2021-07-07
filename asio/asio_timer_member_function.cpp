#include<chrono>
#include<functional>
#include<iostream>

#include<boost/asio.hpp>


class Printer
{
public:
    Printer(boost::asio::io_context& io):
    timer_(io, std::chrono::seconds(1)),
    count_(0)
    {
        timer_.async_wait(std::bind(&Printer::timer_cb, this, std::placeholders::_1));
    }

    ~Printer()
    {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void timer_cb(const boost::system::error_code& e)
    {   
        std::cout << "error_code is " << e << std::endl;

        if(count_ < 5)
        {
            std::cout << "Calling timer_cb: " << count_ << "!" << std::endl;
            ++count_;
            timer_.expires_at(timer_.expiry() + std::chrono::seconds(1));
            timer_.async_wait(std::bind(&Printer::timer_cb, this, std::placeholders::_1));
        }
        else{
            std::cout << "Finishing calling timer_cb!" << std::endl;
        }
    }
private:
    boost::asio::steady_timer timer_;
    int count_;
};


int main(int argc, char** argv)
{
    boost::asio::io_context io;
    Printer p(io);
    io.run();

    return 0;
}