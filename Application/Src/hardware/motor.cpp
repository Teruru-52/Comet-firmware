/*
 * motor.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/motor.h"

namespace hardware
{
    int Motor::GetDuty(float input_vol)
    {
        return (int)((float)MAX_INPUT * input_vol / GetBatteryVoltage());
    }

    void Motor::Drive(float v_left, float v_right)
    {
        duty_left = GetDuty(v_left);
        duty_right = GetDuty(v_right);

        PWM_Update(&motorL, duty_left);
        PWM_Update(&motorR, duty_right);
    }

    void Motor::Brake()
    {
        PWM_Update(&motorL, 0);
        PWM_Update(&motorR, 0);
    }
}