//
//  ModeIdle.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef MODE_IDLE_HPP
#define MODE_IDLE_HPP

#include "Mode.hpp"
#include <Arduino.h>
#include "Core/SystemController.hpp"

namespace Core
{
    namespace Mode
    {
        /**
         * Defines the behaviour of the system when in idle
         */
        class ModeIdle : public Mode
        {
            unsigned long millisLastUpdatedSensors = 0;
            unsigned int updateSensorPeriod = 1000; // milli seconds
        public:
            /**
             * Defines the behaviour of the system when in idle
             */
            ModeIdle(Core::SystemController *sysCtrl);
            ~ModeIdle();
            bool init();
            bool run();

            /**
             * Gets the name of the mode as a string
             */
            String toString();
        };
    } // namespace Mode
} // namespace Core

#endif /* MODE_IDLE_HPP */