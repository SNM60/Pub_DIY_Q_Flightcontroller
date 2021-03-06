/***********************************************************************************
* BMP280.h
*
* Implementation the BMP280
* See: http://www.bosch.com
*
* Date			Author          Notes
* 30/01/2017	Stefan Meyre    Initial release
 *
***********************************************************************************/

#ifndef BMP280_H
#define BMP280_H

//    I2C ADDRESS/BITS/SETTINGS
//    -----------------------------------------------------------------------

#define BMP280_ADDRESS                (0x76 << 1)
#define BMP280_CHIPID                 0x58

//    REGISTERS
//    -----------------------------------------------------------------------

#define     BMP280_REGISTER_STARTDATA           0xF7
#define     BMP280_REGISTER_STARTCALIB          0x88

#define     BMP280_REGISTER_DIG_T1              0x88
#define     BMP280_REGISTER_DIG_T2              0x8A
#define     BMP280_REGISTER_DIG_T3              0x8C

#define     BMP280_REGISTER_DIG_P1              0x8E
#define     BMP280_REGISTER_DIG_P2              0x90
#define     BMP280_REGISTER_DIG_P3              0x92
#define     BMP280_REGISTER_DIG_P4              0x94
#define     BMP280_REGISTER_DIG_P5              0x96
#define     BMP280_REGISTER_DIG_P6              0x98
#define     BMP280_REGISTER_DIG_P7              0x9A
#define     BMP280_REGISTER_DIG_P8              0x9C
#define     BMP280_REGISTER_DIG_P9              0x9E

#define     BMP280_REGISTER_CHIPID              0xD0
#define     BMP280_REGISTER_VERSION             0xD1
#define     BMP280_REGISTER_SOFTRESET           0xE0
#define     BMP280_REGISTER_CAL26               0xE1  // R calibration stored in 0xE1-0xF0

#define     BMP280_REGISTER_CONTROL             0xF4
#define     BMP280_REGISTER_CONFIG              0xF5
#define     BMP280_REGISTER_PRESSUREDATA        0xF7
#define     BMP280_REGISTER_TEMPDATA            0xFA

//    CALIBRATION DATA
//    -----------------------------------------------------------------------
typedef struct
{
	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;

	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;

	uint8_t dig_H1;
	int16_t dig_H2;
	uint8_t dig_H3;
	int16_t dig_H4;
	int16_t dig_H5;
	int8_t dig_H6;
} bmp280_calib_data;

#endif

int32_t t_fine;
int32_t adc_P;
int32_t adc_T;
uint8_t dataReadyfromBMP280;
bmp280_calib_data _bmp280_calib;

void BMP280_Init(void);
void readPandT(uint8_t reg, uint8_t buffer[24]);
double calcBMP280Temperature(void);
double calcBMP280Pressure(void);
double calcDoubleBMP280Temperature(void);
double calcDoubleBMP280Pressure(void);
double calcDoubleBMP280Altitude(double seaLevelhPa);
