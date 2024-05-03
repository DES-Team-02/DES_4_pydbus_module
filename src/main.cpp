#include <CommonAPI/CommonAPI.hpp>
#include "JetsonStubImpl.hpp"
#include <thread>

using namespace v0::commonapi;

int main()
{
	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

	std::string domain = "local";
	std::string instance = "commonapi.Jetson";
	std::string connection = "jeston";

	std::shared_ptr<JetsonStubImpl> myService = std::make_shared<JetsonStubImpl>();
	while (!runtime->registerService(domain, instance, myService, connection))
	{
		std::cout << "Register Service failed, trying again in 100 milliseconds" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	};
	std::cout << "Successfully Registered Jetson Service" << std::endl;
}