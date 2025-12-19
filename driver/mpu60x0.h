#ifndef MPU60X0_H
#define MPU60X0_H

#include "stm32xxxx_hal.h" 

#define MPU60X0_SMPLRT_DIV   0x19
#define MPU60X0_CONFIG       0x1A
#define MPU60X0_GYRO_CONFIG  0x1B
#define MPU60X0_ACCEL_CONFIG 0x1C
#define MPU60X0_ACCEL_XOUT_H 0x3B
#define MPU60X0_TEMP_OUT_H   0x41
#define MPU60X0_GYRO_XOUT_H  0x43
#define MPU60X0_PWR_MGMT_1   0x6B
#define MPU60X0_WHO_AM_I     0x75

typedef struct {
    I2C_HandleTypeDef *hi2c; 
    uint16_t devAddr;       
    float accelMult;        
    float gyroMult;          
} MPU60X0_t;


HAL_StatusTypeDef MPU60X0_Init(MPU60X0_t *dev, I2C_HandleTypeDef *hi2c, uint16_t addr);
HAL_StatusTypeDef MPU60X0_ReadData(MPU60X0_t *dev, float *accel, float *gyro, float *temp);

#endif
