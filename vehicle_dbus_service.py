from pydbus import SessionBus
from gi.repository import GLib
from pydbus.generic import signal
from vehicle_control import VehicleControl

class VehicleControlDBusService:
    """
    D-Bus Service Interface for VehicleControl.
    """
    dbus = """
    <node>
        <interface name='com.team2.VehicleControl'>
            <method name='SetSteering'>
                <arg type='i' name='value' direction='in'/>
            </method>
            <method name='SetSpeed'>
                <arg type='i' name='value' direction='in'/>
            </method>
            <property name='Steering' type='i' access='read'/>
            <property name='Speed' type='i' access='read'/>
            <signal name='SteeringChanged'>
                <arg type='i' name='newSteering'/>
            </signal>
            <signal name='SpeedChanged'>
                <arg type='i' name='newSpeed'/>
            </signal>
        </interface>
    </node>
    """

    def __init__(self):
        self.vehicle = VehicleControl()

    def SetSteering(self, value):
        self.vehicle.steering = value
        self.SteeringChanged(value)
        return f"Steering set to {value}"

    def SetSpeed(self, value):
        self.vehicle.speed = value
        self.SpeedChanged(value)
        return f"Speed set to {value}"
    
    SteeringChanged = signal()
    SpeedChanged = signal()

    @property
    def Steering(self):
        return self.vehicle.steering

    @property
    def Speed(self):
        return self.vehicle.speed
    
# if __name__ == "__main__":
#     bus = SessionBus()
#     service = VehicleControlDBusService()
#     bus.publish("com.example.VehicleControl", service)
#     print("VehicleControl D-Bus service running.")
#     loop = GLib.MainLoop()
#     loop.run()
