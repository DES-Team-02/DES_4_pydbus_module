#include "JetsonProxyImpl.hpp"
#include <thread>
#include <chrono>

JetsonProxyImpl::JetsonProxyImpl() {
    // Initialize CommonAPI runtime
    runtime = CommonAPI::Runtime::get();
    std::string domain      = "local";
    std::string instance    = "commonapi.Jetson";
    std::string connection  = "jetson-proxy";
    
    auto myProxy = runtime->buildProxyWithDefaultAttributeExtension<JetsonProxy, CommonAPI::Extensions::AttributeCacheExtension>(domain, instance, connection);

    while (!myProxy->isAvailable()) {
        std::cout << "Waiting for SOME/IP server to become available..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "SOME/IP server is available" << std::endl;

    // Set callbacks for received data
    myProxy->getSteeringAttribute().getChangedEvent().subscribe([this](double value) {
        std::cout << "Received steering: " << value << std::endl;
    });

    myProxy->getThrottleAttribute().getChangedEvent().subscribe([this](double value) {
        std::cout << "Received throttle: " << value << std::endl;
    });
}
