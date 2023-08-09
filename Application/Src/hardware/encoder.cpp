/*
 * encoder.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/encoder.h"
#include <cmath>

namespace hardware
{
    EncoderBase::EncoderBase(float gear_ratio)
        : gear_ratio(gear_ratio) {}

    float EncoderBase::GetAngle() const { return theta; }
    float EncoderBase::GetAngularVelocity() const { return omega; }

    AS5055A::AS5055A(SPI_Value *spi_value, float sampling_period)
        : EncoderBase(gear_ratio),
          spi_value(spi_value),
          sampling_period(sampling_period) {}

    void AS5055A::Update()
    {
        int16_t raw_angle = Read_2byte(spi_value, 0x3F, 0xFF, 2, 10);
        theta = (float)raw_angle / (float)(2 << 14) * 2.0f * M_PI;
        // omega =
    }

    void AS5055A::Reset()
    {
    }
} // namespace hardware