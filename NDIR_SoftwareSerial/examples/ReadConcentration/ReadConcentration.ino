#include <SoftwareSerial.h>
#include <NDIR_SoftwareSerial.h>

//Select 2 digital pins as SoftwareSerial's Rx and Tx. For example, Rx=2 Tx=3
NDIR_SoftwareSerial mySensor(2, 3);

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
