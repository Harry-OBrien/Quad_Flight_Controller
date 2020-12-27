//
//  Barometer.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef BAROMETER_HPP
#define BAROMETER_HPP

#include <Adafruit_BMP280.h>
#include "Device.hpp"

namespace Dynamics
{
    namespace Sensing
    {
        namespace Device
        {
            class Barometer : public Device
            {
                Adafruit_BMP280 bmp;
                const float referencePressure = 1035.9;

            public:
                Barometer();
                ~Barometer();

                /**
                 * Initialises the barometer and validates that it is alive
                 */
                bool initialise();

                /**
                 * Reads the latest data from the barometer
                 */
                PhysicalState getReading();
            };
        } // namespace Device

    } // namespace Sensing

} // namespace Dynamics

#endif /* BAROMETER_HPP */