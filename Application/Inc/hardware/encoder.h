/*
 * encoder.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "main.h"
#include "spi.h"

namespace hardware
{
    class EncoderBase
    {
    private:
        float GetAngle() const;
        float GetAngularVelocity() const;

    protected:
        EncoderBase(float gear_ratio);

        float theta = 0.0;
        float pre_theta = 0.0;
        float omega = 0.0;
        float gear_ratio;
        // float gear_ratio = 9.0f / 35.0f;
        // float tire_radius = 0.006; // [m]
    };

    class AS5055A : public EncoderBase
    {
    protected:
        AS5055A(SPI_Value *spi_value, float sampling_period);

        void Update();
        void Reset();

    private:
        SPI_Value *spi_value;
        float sampling_period; // [s]
    };
} // namespace hardware

#endif // ENCODER_H_