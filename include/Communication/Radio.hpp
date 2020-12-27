//
//  Radio.hpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef RADIO_HPP
#define RADIO_HPP

#include <SBUS.h>
#include <Arduino.h>

namespace Coms
{
    class Radio
    {
        SBUS receiverInterface;
        uint16_t channels[16];
        bool failSafe;
        bool lostFrame;

    public:
        Radio();
        bool init();
        void update();

        /**
         * gets the latest packet that was read from the receiver (after update was called)
         */
        uint16_t *getLatestPacket();

        void printMessage();
    };
} // namespace Coms

#endif /* RADIO_HPP */
