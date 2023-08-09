/*
 * led.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef LED_H_
#define LED_H_

#include "main.h"

namespace hardware
{
    class LED
    {
    public:
        void on_all();
        void off_all();

        void Flashing();
    };
} // namespace hardware

#endif // LED_H_