/*
Description:
This is a example code for Sandbox Electronics NDIR CO2 sensor module.
You can get one of those products on
http://sandboxelectronics.com

Version:
V1.2

Release Date:
2018-10-16

Author:
Tiequan Shao          support@sandboxelectronics.com

Lisence:
CC BY-NC-SA 3.0

Please keep the above information when you use this code in your project.
*/

#ifndef _NDIR_I2C_H_
#define _NDIR_I2C_H_

class NDIR_I2C {
    public:
		NDIR_I2C(uint8_t i2c_addr);

        uint8_t  i2c_addr;
        uint32_t ppm;

        uint8_t  begin();
        uint8_t  measure();
        uint8_t  reset();
        void     calibrateZero();
        void     enableAutoCalibration();
        void     disableAutoCalibration();

    private:
	    static uint8_t cmd_measure[9];
        static uint8_t cmd_calibrateZero[9];
        static uint8_t cmd_enableAutoCalibration[9];
        static uint8_t cmd_disableAutoCalibration[9];

        uint8_t  send(uint8_t *pdata, uint8_t n);
        uint8_t  receive(uint8_t *pbuf, uint8_t n);
        uint8_t  read_register(uint8_t reg_addr, uint8_t *pval);
        uint8_t  write_register(uint8_t reg_addr, uint8_t *pdata, uint8_t n);
        uint8_t  write_register(uint8_t reg_addr, uint8_t val);
        uint8_t  parse (uint8_t *pbuf);
};
#endif
