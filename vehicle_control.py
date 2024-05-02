class VehicleControl:
    def __init__(self):
        self._steering = 0
        self._speed = 0
    
    @property
    def steering(self):
        return self._steering
    
    @steering.setter
    def steering(self, value):
        self._steering = value
        #For debugging
        print(f"Steering set to {self._steering}")
        
    @property
    def speed(self):
        return self._speed
    
    @speed.setter
    def speed(self, value):
        self._speed = value
        #For debugging
        print(f"Speed set to {self._speed}")    
    