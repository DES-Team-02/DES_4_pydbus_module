#include <dbus-c++-1/dbus-c++/dbus.h>
#include <CommonAPI/CommonAPI.hpp>
#include <iostream>
#include "VehicleControlProxyImpl.hpp"

VehicleControlProxyImpl::VehicleControlProxyImpl(DBus::Connection& connection, const char* path, const char* name)
    : DBus::ObjectProxy(connection, path, name)
{};

void VehicleControlProxyImpl::setService(std::shared_ptr<JetsonStubImpl> service)
{
    _jetsonService = service;
}

void VehicleControlProxyImpl::SteeringChanged(const double& newSteering)
{
    std::cout << "Steering updated to: " << newSteering << std::endl;
    _jetsonService->setSteeringAttribute(newSteering);
}

void VehicleControlProxyImpl::ThrottleChanged(const double& newThrottle)
{
    std::cout << "Speed updated to: " << newThrottle << std::endl;
    _jetsonService->setThrottleAttribute(newThrottle);
}