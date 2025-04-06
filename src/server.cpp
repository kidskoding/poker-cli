#include <boost/asio.hpp>
#include <exception>
#include <iostream>

using boost::asio::ip::tcp;

void run_server() {
	int port = 8080;

	try {
		boost::asio::io_context io_context;

		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

		std::cout << "server is running on port " << port << std::endl;

		while(true) {
			tcp::socket socket(io_context);
			acceptor.accept(socket);
		}
	} catch(std::exception& e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}
}

int main() {
	run_server();
	return 0;
}