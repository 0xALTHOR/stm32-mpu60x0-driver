#include "mpu60x0.h"

HAL_StatusTypeDef MPU60X0_Init(MPU60X0_t *dev, I2C_HandleTypeDef *hi2c, uint16_t addr) {
    dev->hi2c = hi2c;
    dev->devAddr = (addr << 1); 

    uint8_t check, data;

    
    HAL_I2C_Mem_Read(dev->hi2c, dev->devAddr, MPU60X0_WHO_AM_I, 1, &check, 1, 100);
    if (check != 0x68) return HAL_ERROR;

    
    data = 0x00;
    HAL_I2C_Mem_Write(dev->hi2c, dev->devAddr, MPU60X0_PWR_MGMT_1, 1, &data, 1, 100);

    
    data = 0x00; 
    HAL_I2C_Mem_Write(dev->hi2c, dev->devAddr, MPU60X0_ACCEL_CONFIG, 1, &data, 1, 100);
    dev->accelMult = 16384.0f; 


    data = 0x00; 
    HAL_I2C_Mem_Write(dev->hi2c, dev->devAddr, MPU60X0_GYRO_CONFIG, 1, &data, 1, 100);
    dev->gyroMult = 131.0f; 

    return HAL_OK;
}

HAL_StatusTypeDef MPU60X0_ReadData(MPU60X0_t *dev, float *accel, float *gyro, float *temp) {
    uint8_t buffer[14]; 
    
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(dev->hi2c, dev->devAddr, MPU60X0_ACCEL_XOUT_H, 1, buffer, 14, 100);
    
    if (status == HAL_OK) {
        
        accel[0] = (int16_t)(buffer[0] << 8 | buffer[1]) / dev->accelMult;
        accel[1] = (int16_t)(buffer[2] << 8 | buffer[3]) / dev->accelMult;
        accel[2] = (int16_t)(buffer[4] << 8 | buffer[5]) / dev->accelMult;

        
        int16_t rawTemp = (int16_t)(buffer[6] << 8 | buffer[7]);
        *temp = (rawTemp / 340.0f) + 36.53f; 

        
        gyro[0] = (int16_t)(buffer[8] << 8 | buffer[9]) / dev->gyroMult;
        gyro[1] = (int16_t)(buffer[10] << 8 | buffer[11]) / dev->gyroMult;
        gyro[2] = (int16_t)(buffer[12] << 8 | buffer[13]) / dev->gyroMult;
    }
    return status;
}
