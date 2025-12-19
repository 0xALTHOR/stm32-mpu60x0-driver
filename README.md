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


## Usage
```c
MPU60X0_t imu;
float a[3], g[3], temp;

// Initialize with I2C address 0x68
if (MPU60X0_Init(&imu, &hi2c1, 0x68) == HAL_OK) {
    while(1) {
        MPU60X0_ReadData(&imu, a, g, &temp);
        HAL_Delay(10);
    }
}

```

Keynotes: Configure your I2C to 400kHz
          If the AD0 pin is connected to GND, use address 0x68. If connected to VDD, use 0x69.
          Ensure VDD is between 2.375V and 3.46V so you dont burn the chip!!
