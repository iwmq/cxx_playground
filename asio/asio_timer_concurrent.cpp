#include<chrono>
// #include<functional>
#include<iostream>
#include<thread>

#include<boost/asio.hpp>
#include<boost/bind/bind.hpp>


class Printer
{
public:
    Printer(boost::asio::io_context& io)
        : strand_(boost::asio::make_strand(io)),
         timer1_(io, std::chrono::seconds(1)),
         timer2_(io, std::chrono::seconds(1)),
         count_(0)
    {
        timer1_.async_wait(boost::asio::bind_executor(strand_,
            boost::bind(&Printer::timer1_cb, this, std::placeholders::_1)));
        timer2_.async_wait(boost::asio::bind_executor(strand_,
            boost::bind(&Printer::timer2_cb, this, std::placeholders::_1)));
    }

    ~Printer()
    {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void timer1_cb(const boost::system::error_code& /*e*/)
    {   
        if(count_ < 5)
        {
            std::cout << "Calling timer1_cb: " << count_ << "!" << std::endl;
            ++count_;
            timer1_.expires_at(timer1_.expiry() + std::chrono::seconds(1));
            timer1_.async_wait(boost::asio::bind_executor(strand_,
                boost::bind(&Printer::timer1_cb, this, std::placeholders::_1)));
        }
        else{
            std::cout << "Finishing calling timer1_cb!" << std::endl;
        }
    }

    void timer2_cb(const boost::system::error_code& /*e*/)
    {   
        if(count_ < 5)
        {
            std::cout << "Calling timer2_cb: " << count_ << "!" << std::endl;
            ++count_;
            timer2_.expires_at(timer2_.expiry() + std::chrono::seconds(1));
            timer2_.async_wait(boost::asio::bind_executor(strand_,
                boost::bind(&Printer::timer2_cb, this, std::placeholders::_1)));
        }
        else{
            std::cout << "Finishing calling timer2_cb!" << std::endl;
        }
    }
private:
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_, timer2_;
    int count_;
};


int main(int argc, char** argv)
{
    boost::asio::io_context io;
    Printer p(io);

    // Run in another thread
    // NOTE: std::bind fails to compile
    std::thread t(boost::bind(&boost::asio::io_context::run, &io));
    io.run();
    t.join();

    return 0;
}