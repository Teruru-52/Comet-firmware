/*
 * imu.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef IMU_H_
#define IMU_H_

#include "main.h"
#include "spi.h"

namespace hardware
{
    class IMUBase
    {
    private:
        // virtual void Initialize();
        float GetAngle() const;
        float GetAngularVelocity() const;
        float GetAx() const;

    protected:
        // IMUBase();

        float yaw = 0.0;
        float gz = 0.0;
        float ax = 0.0;
    };

    class ICM20600 : public IMUBase
    {
    protected:
        ICM20600(SPI_Value *spi_value, float sampling_period);

        void Initialize();
        void Update();
        void UpdateGyro();
        void UpdateAcc();
        void Reset();

    private:
        SPI_Value *spi_value;
        float sampling_period; // [s]

        const float gyro_factor = 16.6;
        const float acc_factor = 8192.0;
        float offset_gz = 0.0;
    };
} // namespace hardware

#endif // IMU_H_