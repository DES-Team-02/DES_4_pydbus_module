#pragma once

#include <dbus-c++-1/dbus-c++/dbus.h>
#include <CommonAPI/CommonAPI.hpp>
#include "VehicleControlProxy.hpp"
#include "JetsonStubImpl.hpp"

class VehicleControlProxyImpl : public com::team2::VehicleControl_proxy,
                            public DBus::IntrospectableProxy,
                            public DBus::ObjectProxy 
{
private:
    std::shared_ptr<JetsonStubImpl> _jetsonService;
public:
    VehicleControlProxyImpl(DBus::Connection& connection, const char* path, const char* name);
    void setService(std::shared_ptr<JetsonStubImpl> service);
    virtual void SteeringChanged(const double& newSteering);
    virtual void ThrottleChanged(const double& newThrottle);
};