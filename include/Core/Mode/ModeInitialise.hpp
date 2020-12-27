//
//  ModeInitialise.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef MODE_INITIALISE_HPP
#define MODE_INITIALISE_HPP

#include "Mode.hpp"
#include "Core/SystemController.hpp"
#include <Arduino.h>

namespace Core
{
    namespace Mode
    {
        class ModeInitialise : public Mode
        {
        public:
            ModeInitialise(Core::SystemController *sysCtrl);
            ~ModeInitialise();
            bool init();
            bool run();

            /**
             * Gets the name of the mode as a string
             */
            String toString();
        };
    } // namespace Mode
} // namespace Core

#endif /* MODE_INITIALISE_HPP */