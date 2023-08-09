/*
 * ir_sensor.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include "main.h"

namespace hardware
{
    struct IR_Value
    {
        uint32_t fl;
        uint32_t fr;
        uint32_t sl;
        uint32_t sr;
    };

    struct IR_Base
    {
        float is_wall;
        float fl;
        float fr;
        float sl;
        float sr;
    };

    class IRsensor
    {
    private:
        const int senser_num = 4;
        float ir_start_base;
        float ir_wall_base;

        uint16_t dma[4];

        IR_Value ir_value;
        IR_Value max_value;

    public:
        IRsensor(float ir_start_base, float ir_wall_base);

        void on_front_led();
        void on_side_led();
        void off_front_led();
        void off_side_led();
        void on_all_led();
        void off_all_led();

        void UI_led_onoff();
        void UI_led_off();

        void UpdateValue();
        void Update();
        IR_Value GetIRSensorData();
        void BatteryCheck();
        bool StartInitialize();
    };
}

#endif // IR_SENSOR_H_