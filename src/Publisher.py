# main_publish.py

from VehicleDbusService import VehicleControlDBusService
from pydbus import SessionBus
from gi.repository import GLib
import time
from threading import Thread

def update_values(service):
    value = -1
    offset = 0.1
    while True:
        value += offset
        service.SetSteering(value)
        time.sleep(1)
        if value == 1:
            offset = -offset

if __name__ == "__main__":
    bus = SessionBus()
    service = VehicleControlDBusService()
    bus.publish("com.team2.VehicleControl", service)
    print("VehicleControl D-Bus service is running.")

    update_thread = Thread(target=update_values, args=(service,))
    update_thread.start()

    loop = GLib.MainLoop()
    loop.run()
