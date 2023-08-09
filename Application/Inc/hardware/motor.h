/*
 * motor.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "main.h"

namespace hardware
{
    class Motor
    {
    private:
        int duty_left;
        int duty_right;

    public:
        int GetDuty(float input_vol);
        void Drive(float v_left, float v_right);
        void Brake();
    };
} // namespace hardware

#endif // MOTOR_H_