import NDIR
import time

sensor = NDIR.Sensor(0x4D)
sensor.begin()

while True:
    sensor.measure()
    print("CO2 Concentration: " + str(sensor.ppm) + "ppm")
    time.sleep(1)
