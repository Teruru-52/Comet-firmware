/*
 * speaker.h
 *
 *  Created on: June 15th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "main.h"

namespace hardware
{
    class Speaker
    {
    public:
        void Beep();
        void SpeakerOn();
        void SpeakerOff();
    };
} // namespace hardware

#endif // SPEAKER_H_