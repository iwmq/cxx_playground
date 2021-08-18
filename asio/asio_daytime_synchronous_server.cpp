#include<array>
#include<ctime>
#include<iostream>

#include<boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    auto now = std::time(0);
    return std::ctime(&now);
}

int main(int argc, char** argv)
{
    try
    {
        boost::asio::io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
        tcp::socket socket(io);

        while (true)
        {
            acceptor.accept(socket);
            auto message = make_daytime_string();

            boost::system::error_code ignore_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignore_error);

            socket.close();
        }

    } catch(std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}