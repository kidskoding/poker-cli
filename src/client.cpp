#include <boost/asio.hpp>
#include "client.h"
#include <iostream>
#include <string>

void connect() {
    std::string host = "127.0.0.1";
    int port = 8080;

    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, std::to_string(port));
        tcp::socket socket(io_context);

        boost::asio::connect(socket, endpoints);

    } catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}