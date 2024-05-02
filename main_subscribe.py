from pydbus import SessionBus
from gi.repository import GLib

def on_steering_changed(newSteering):
    print(f"Steering updated to: {newSteering}")

def on_speed_changed(newSpeed):
    print(f"Speed updated to: {newSpeed}")

if __name__ == "__main__":
    bus = SessionBus()
    proxy = bus.get("com.team2.VehicleControl")
    proxy.SteeringChanged.connect(on_steering_changed)
    proxy.SpeedChanged.connect(on_speed_changed)

    loop = GLib.MainLoop()
    loop.run()