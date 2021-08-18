#include<array>
#include<ctime>
// #include<memory>
#include<iostream>

#include<boost/shared_ptr.hpp>
#include<boost/bind/bind.hpp>
#include<boost/enable_shared_from_this.hpp>
#include<boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    auto now = std::time(0);
    return std::ctime(&now);
}


class TCP_Connection :
    public boost::enable_shared_from_this<TCP_Connection>
{
    public:
        // std::shared_ptr does not work here
        typedef boost::shared_ptr<TCP_Connection> pointer;

        static pointer create(boost::asio::io_context& io)
        {
            return pointer(new TCP_Connection(io));
        }
        
        tcp::socket& socket()
        {
            return socket_;
        }

        void start()
        {
            message_ = make_daytime_string();
            boost::asio::async_write(socket_,
                boost::asio::buffer(message_),
                boost::bind(
                    &TCP_Connection::handle_write,
                    shared_from_this(),
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred
                )
            );
        }
    
    private:
        TCP_Connection(boost::asio::io_context& io)
            : socket_(io)
        {
        }

        void handle_write(const boost::system::error_code& /*e*/,
            size_t /*len*/)
        {
        }

        tcp::socket socket_;
        std::string message_;
};


class TCP_Server
{
    public:
        TCP_Server(boost::asio::io_context& io)
            : io_(io), acceptor_(io, tcp::endpoint(tcp::v4(), 13))
        {
            start_accept();
        }
    
    private:
        void start_accept()
        {
            TCP_Connection::pointer con = TCP_Connection::create(io_);
            acceptor_.async_accept(con->socket(), 
                boost::bind(&TCP_Server::handle_accept,
                    this,
                    con,
                    boost::asio::placeholders::error)
            ); 
        }

        void handle_accept(TCP_Connection::pointer con,
            const boost::system::error_code& error)
        {
            if (!error)
            {
                con->start();
            }

            start_accept();
        }

        boost::asio::io_context& io_;
        tcp::acceptor acceptor_;
};


int main(int argc, char** argv)
{
    try
    {
        boost::asio::io_context io;
        TCP_Server server(io);
        io.run();
    } catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}