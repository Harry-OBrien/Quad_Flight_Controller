//
//  ModeArm.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef MODE_ARM_HPP
#define MODE_ARM_HPP

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
        class ModeArm : public Mode
        {
        public:
            /**
             * Defines the behaviour of the system when arming
             */
            ModeArm(Core::SystemController *sysCtrl);
            ~ModeArm();
            bool init();
            bool run();

            /**
             * Gets the name of the mode as a string
             */
            String toString();
        };
    } // namespace Mode
} // namespace Core

#endif /* MODE_ARM_HPP */