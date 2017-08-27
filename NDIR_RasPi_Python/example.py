import NDIR
import time

sensor = NDIR.Sensor(0x4D)

if sensor.begin() == False:
    print("Adaptor initialization FAILED!")
    exit()

while True:
    if sensor.measure():
        print("CO2 Concentration: " + str(sensor.ppm) + "ppm")
    else:
        print("Sensor communication ERROR.")

    time.sleep(1)
