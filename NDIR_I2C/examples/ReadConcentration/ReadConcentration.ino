#include <Wire.h>
#include <NDIR_I2C.h>

NDIR_I2C mySensor(0x4D); //Adaptor's I2C address (7-bit, default: 0x4D)

void setup()
{
    Serial.begin(9600);

    if (mySensor.begin()) {
        Serial.println("Wait 10 seconds for sensor initialization...");
        delay(10000);
    } else {
        Serial.println("ERROR: Failed to connect to the sensor.");
        while(1);
    }
}

void loop() {
    if (mySensor.measure()) {
        Serial.print("CO2 Concentration is ");
        Serial.print(mySensor.ppm);
        Serial.println("ppm");
    } else {
        Serial.println("Sensor communication error.");
    }

    delay(1000);
}
