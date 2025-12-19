#include "main.h"
#include "mpu60x0.h"
#include <stdio.h>


I2C_HandleTypeDef hi2c1;
MPU60X0_t imu;


float accelData[3]; 
float gyroData[3];  
float tempCelsius;

int main(void) {

    HAL_Init();
    SystemClock_Config();
    MX_I2C1_Init(); // Ensure I2C is set to 400kHz 

    
    // 0x68 is the default address if AD0 is grounded 
    if (MPU60X0_Init(&imu, &hi2c1, 0x68) != HAL_OK) {

        while(1);
    }

    while (1) {
       
        if (MPU60X0_ReadData(&imu, accelData, gyroData, &tempCelsius) == HAL_OK) {
           

        }

        HAL_Delay(50); 
    }
}