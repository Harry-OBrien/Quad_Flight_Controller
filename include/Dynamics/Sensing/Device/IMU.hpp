//
//  IMU.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef IMU_HPP
#define IMU_HPP

#include <SparkFunMPU9250-DMP.h>
#include "Device.hpp"

namespace Dynamics
{
    namespace Sensing
    {
        namespace Device
        {
            class IMU : public Device
            {
                MPU9250_DMP mpu9250;

                PhysicalState latestValidReading;

            public:
                IMU();
                ~IMU();

                /**
                 * Initialises the IMU and validates that it is alive
                 */
                bool initialise();

                /**
                 * Reads the latest data from the IMU
                 */
                PhysicalState getReading();

            private:
                void updateLatestReading();
            };
        } // namespace Device

    } // namespace Sensing

} // namespace Dynamics

#endif /* IMU_HPP */