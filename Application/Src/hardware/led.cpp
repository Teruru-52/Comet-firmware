/*
 * led.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/led.h"

namespace hardware
{
    void LED::on_all()
    {
        Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_SET);
        Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_SET);
        Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_SET);
        Write_GPIO(SIDE_RIGHT_LED, GPIO_PIN_SET);
    }

    void LED::off_all()
    {
        Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_RESET);
        Write_GPIO(FRONT_RIGHT_LED, GPIO_PIN_RESET);
        Write_GPIO(FRONT_LEFT_LED, GPIO_PIN_RESET);
        Write_GPIO(SIDE_LEFT_LED, GPIO_PIN_RESET);
    }

    void LED::Flashing()
    {
        for (int i = 0; i < 2; i++)
        {
            on_all();
            HAL_Delay(500);
            off_all();
            HAL_Delay(500);
        }
    }

}