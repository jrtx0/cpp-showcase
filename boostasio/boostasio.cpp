#include <iostream>
#include <boost/asio.hpp>
#include <chrono>

void print(boost::system::error_code ec) {
  std::cout << "Hello, world!" << std::endl;
}

int main() {
  boost::asio::io_context ioc;
  boost::asio::steady_timer timer(ioc, std::chrono::seconds(3));
  timer.async_wait(&print);
  ioc.run();
  return 0;
}

/* g++ boostasio.cpp -o boostasio -I/usr/include/boost -lboost_system -pthread */