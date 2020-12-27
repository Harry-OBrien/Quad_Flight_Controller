//
//  Device.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "Dynamics/PhysicalState.hpp"

namespace Dynamics
{
    namespace Sensing
    {
        namespace Device
        {
            class Device
            {
            protected:
                bool initialised;
                bool alive;
                PhysicalState latestReading;

            public:
                Device() : initialised(false),
                           alive(false)
                {
                }

                virtual ~Device() {}

                virtual bool initialise() = 0;
                virtual PhysicalState getReading() = 0;

                bool isInitialised() { return initialised; }
                bool isAlive() { return alive; }
            };

        } // namespace Device

    } // namespace Sensing

} // namespace Dynamics

#endif /* DEVICE_HPP */