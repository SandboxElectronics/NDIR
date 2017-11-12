import NDIR
import time

sensor = NDIR.Sensor(0x4D)

if sensor.begin() == False:
    print("Adaptor initialization FAILED!")
    exit()
sensor.power_on()
print("Power On")
i = 0
while i < 50:
    if i == 25:
        sensor.power_off()
        print("Power Off")
        sensor.ppm = -1
    if sensor.measure():
        print("CO2 Concentration: " + str(sensor.ppm) + "ppm")
    else:
        print("Sensor communication ERROR.")

    time.sleep(1)
    i += 1

