This repository contains Arduino Libraries for Sandbox Electronics NDIR CO2 Sensor with UART/I2C Interface:
http://sandboxelectronics.com/?product=mh-z16-ndir-co2-sensor-with-i2cuart-5v3-3v-interface-for-arduinoraspeberry-pi

It contains two libraries. Normally only one is needed.
  - NDIR_I2C: for communication with the sensor via I2C.
  - NDIR_SoftwareSerial: for communication with the sensor via UART (SoftwareSerial).

Note: The dip switch on the adaptor should be set to I2C or UART accordingly to select I2C or UART mode communication.

Installling the library (the automatic way)
  1. Click "Download ZIP" button in the top right cornor of this github page and uncompress it.
  2. From the Arduino IDE, Click Sketch->Include Library->Add .ZIP Library..., a file explorer window should popup.
  3. In the popup windows, navigate to the folder what was just uncompressed.
  4. Select one of the following folders:
    - NDIR_I2C (which contains NDIR_I2C.cpp and NDIR_I2C.h)
    - NDIR_SoftwareSerial (which contains NDIR_SoftwareSerial.cpp and NDIR_SoftwareSerial.h)
  5. Click Open.
  6. Restart the Arduino IDE. The library should now be ready for use.

Installling the library (the manual way)
  1. Click "Download ZIP" button in the top right cornor of this github page and uncompress it.
  2. From the uncompressed folder, copy one of the following folders to the <Arduino Sketchbook>/libraries/ folder. You may need to create the libraries subfolder if it does not already exist.
    - NDIR_I2C (which contains NDIR_I2C.cpp and NDIR_I2C.h)
    - NDIR_SoftwareSerial (which contains NDIR_SoftwareSerial.cpp and NDIR_SoftwareSerial.h)
  3. Restart the Arduino IDE. The library should now be ready for use.

It is recommended to use the automatic way because it automatically places the libraries to the correct path. For manual installation, the path of <Arduino Sketchbook> folder can be found by clicking File->Preferences in the Arduino IDE. The Sketchbook location is on the top of the Preferences page.
  - On Windows, libraries folder is normally located at "My Documents\Arduino\libraries"
  - On Mac, libraries folder is normally located at "Documents/Arduino/libraries"
  - On Linux, libraries folder is normally located at "/home/<user>/sketchbook/libraries"
  
