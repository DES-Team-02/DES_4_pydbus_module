#include <dbus-c++-1/dbus-c++/dbus.h>
#include <iostream>
#include "vehicle_control_proxy.h"

class VehicleControlProxy : public com::team2::VehicleControl_proxy,
                            public DBus::IntrospectableProxy,
                            public DBus::ObjectProxy {
public:
    VehicleControlProxy(DBus::Connection& connection, const char* path, const char* name)
        : DBus::ObjectProxy(connection, path, name) {}

    virtual void SteeringChanged(const int32_t& newSteering) {
        std::cout << "Steering updated to: " << newSteering << std::endl;
    }

    virtual void SpeedChanged(const int32_t& newSpeed) {
        std::cout << "Speed updated to: " << newSpeed << std::endl;
    }
};

int main() {
    DBus::BusDispatcher dispatcher;
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection conn = DBus::Connection::SessionBus();

    VehicleControlProxy proxy(conn, "/com/team2/VehicleControl", "com.team2.VehicleControl");

    dispatcher.enter();
    return 0;
}
