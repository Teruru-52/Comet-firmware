/*
 * imu.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/imu.h"

namespace hardware
{
    float IMUBase::GetAngle() const { return yaw; }
    float IMUBase::GetAngularVelocity() const { return gz; }
    float IMUBase::GetAx() const { return ax; }

    ICM20600::ICM20600(SPI_Value *spi_value, float sampling_period)
        : spi_value(spi_value),
          sampling_period(sampling_period) {}

    void ICM20600::Initialize()
    {
        }

    void ICM20600::Update()
    {
        UpdateGyro();
        UpdateAcc();
    }

    void ICM20600::UpdateGyro()
    {
        int16_t gz_raw;

        // H:8bit shift, Link h and l
        gz_raw = (int16_t)((int16_t)(Read_1byte(spi_value, 0x47, 2, 10) << 8) | Read_1byte(spi_value, 0x48, 2, 10));
        gz = (float)(gz_raw) / gyro_factor * M_PI / 180.0f - offset_gz; // dps to deg/sec
    }

    void ICM20600::UpdateAcc()
    {
    }

} // namespace hardware