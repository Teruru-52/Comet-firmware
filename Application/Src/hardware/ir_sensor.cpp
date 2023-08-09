/*
 * ir_sensor.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/ir_sensor.h"

namespace hardware
{
    IRsensor::IRsensor(float ir_start_base, float ir_wall_base)
        : ir_start_base(ir_start_base),
          ir_wall_base(ir_wall_base) {}

    void IRsensor::on_front_led()
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 50);
    }

    void IRsensor::on_side_led()
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 50);
    }

    void IRsensor::off_front_led()
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
    }

    void IRsensor::off_side_led()
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
    }

    void IRsensor::on_all_led()
    {
        on_front_led();
        on_side_led();
    }

    void IRsensor::off_all_led()
    {
        off_front_led();
        off_side_led();
    }

    void IRsensor::UI_led_onoff()
    {
        if (ir_value.fl > ir_wall_base)
            Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_SET);
        else
            Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_RESET);

        if (ir_value.fr > ir_wall_base)
            Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_SET);
        else
            Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_RESET);

        if (ir_value.sl > ir_wall_base)
            Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_SET);
        else
            Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_RESET);

        if (ir_value.sr > ir_wall_base)
            Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_SET);
        else
            Write_GPIO(SIDE_RIGHT_LED, GPIO_PIN_SET);
    }

    void IRsensor::UI_led_off()
    {
        Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_RESET);
        Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_RESET);
        Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_RESET);
        Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_RESET);
    }

    void IRsensor::UpdateValue()
    {
        if (max_value.sl < dma[0])
        {
            max_value.sl = dma[0];
        }
        if (max_value.sr < dma[3])
        {
            max_value.sr = dma[3];
        }
        if (max_value.fl < dma[1])
        {
            max_value.fl = dma[1];
        }
        if (max_value.fr < dma[2])
        {
            max_value.fr = dma[2];
        }
    }

    void IRsensor::Update()
    {
        ir_value.fl = max_value.fl;
        ir_value.fr = max_value.fr;
        ir_value.sl = max_value.sl;
        ir_value.sr = max_value.sr;

        max_value.fl = 0;
        max_value.fr = 0;
        max_value.sl = 0;
        max_value.sr = 0;

        UI_led_onoff();
    }

    IR_Value IRsensor::GetIRSensorData()
    {
        return ir_value;
    }

    void IRsensor::BatteryCheck()
    {
        float bat_vol = GetBatteryVoltage();
        if (bat_vol > 4.0)
        {
            Write_GPIO(SIDE_RIGHT_LED, GPIO_PIN_SET);
        }
        if (bat_vol > 3.8)
        {
            Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_SET);
        }
        if (bat_vol > 3.6)
        {
            Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_SET);
        }
        if (bat_vol > 3.3)
        {
            Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_SET);
        }
        printf("%f [V]\n", bat_vol);
    }

    bool IRsensor::StartInitialize()
    {
        if (ir_value.sl > ir_start_base && ir_value.sr > ir_start_base)
            return true;
        else
            return false;
    }
}