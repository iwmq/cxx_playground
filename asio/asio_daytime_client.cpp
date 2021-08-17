#include<iostream>
#include<array>

#include<boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char** argv)
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: asio_daytime_client: <host>" << std::endl;
            return 1;
        }
        
        boost::asio::io_context io;
        
        tcp::resolver resolver(io);
        tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

        tcp::socket socket(io);
        boost::asio::connect(socket, endpoints);

        std::array<char, 128> buf;
        // NOTE: the tutorial on boost.asio declares a wrong type for error
        // boost::system::system_error error;
        boost::system::error_code error;
        size_t len;

        while (true)
        {
            len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
                break;  // Connection closed
            else if (error)
                throw boost::system::system_error(error); // Some other error
            
            std::cout.write(buf.data(), len);
        }

        io.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// NOTE: the daytime service can be `time.nist.gov` for test