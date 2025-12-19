# stm32-mpu60x0-driver

 STM32 MPU-60X0 (MPU6000/MPU6050) HAL Driver

 C library for the  MPU-60X0 series using STM32 HAL.

## Features
Support for multiple sensors on the same I2C bus
14-byte burst reads to ensure synchronized motion data
Automatic conversion from raw ADC values to physical units (g, dps, °C)

## Hardware Wiring
| MPU-60X0 Pin | STM32 Pin | Note |
| :--- | :--- | :--- |
| VDD | 3.3V | Power   |
| GND | GND |  Ground|
| SCL | I2C_SCL |  -- |
| SDA | I2C_SDA |Pull-ups required|
| AD0 | GND / 3.3V |Low=0x68, High=0x69 |

Check main_example.c for usage example.
