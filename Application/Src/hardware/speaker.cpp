/*
 * speaker.cpp
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#include "hardware/speaker.h"

namespace hardware
{
    void Speaker::Beep()
    {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 10);
        HAL_Delay(30);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    }

    void Speaker::SpeakerOn()
    {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 10);
    }

    void Speaker::SpeakerOff()
    {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    }

} // namespace hardware