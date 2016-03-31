/*
Description:
This is a example code for Sandbox Electronics NDIR CO2 sensor module.
You can get one of those products on
http://sandboxelectronics.com

Version:
V1.0

Release Date:
2016-03-30

Author:
Tiequan Shao          info@sandboxelectronics.com

Lisence:
CC BY-NC-SA 3.0

Please keep the above information when you use this code in your project.
*/

#include <SoftwareSerial.h>
#include <NDIR_SoftwareSerial.h>
#define  RECEIVE_TIMEOUT  (100)

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class SoftwareSerial;

uint8_t NDIR_SoftwareSerial::cmd_measure[9] = {0xFF,0x01,0x9C,0x00,0x00,0x00,0x00,0x00,0x63};

NDIR_SoftwareSerial::NDIR_SoftwareSerial(uint8_t rx_pin, uint8_t tx_pin) : serial(rx_pin, tx_pin, false)
{
}


uint8_t NDIR_SoftwareSerial::begin()
{
    serial.begin(9600);

    if (measure()) {
        return true;
    } else {
        return false;
    }
}

uint8_t NDIR_SoftwareSerial::measure()
{
    uint8_t i;
    uint8_t buf[9];
    uint32_t start = millis();

    serial.flush();

    for (i=0; i<9; i++) {
        serial.write(cmd_measure[i]);
    }

    for (i=0; i<9;) {
        if (serial.available()) {
            buf[i++] = serial.read();
        }

        if (millis() - start > RECEIVE_TIMEOUT) {
            return false;
        }
    }

    if (parse(buf)) {
        return true;
    }

    return false;
}


uint8_t NDIR_SoftwareSerial::parse(uint8_t *pbuf)
{
    uint8_t i;
    uint8_t checksum = 0;

    for (i=0; i<9; i++) {
        checksum += pbuf[i];
    }

    if (pbuf[0] == 0xFF && pbuf[1] == 0x9C && checksum == 0xFF) {
        ppm = (uint32_t)pbuf[2] << 24 | (uint32_t)pbuf[3] << 16 | (uint32_t)pbuf[4] << 8 | pbuf[5];
        return true;
    } else {
        return false;
    }
}
