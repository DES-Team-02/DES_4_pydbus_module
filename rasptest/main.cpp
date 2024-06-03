#include "JetsonProxyImpl.hpp"
#include <thread>
#include <chrono>
int main() {
    // Initialize the SOME/IP client
    JetsonProxyImpl client;

    // Keep the program running to handle incoming SOME/IP messages
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
