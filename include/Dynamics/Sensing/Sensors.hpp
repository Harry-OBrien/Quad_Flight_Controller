//
//  Sensors.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <Arduino.h>
#include <vector>

// Devices
#include "Device/IMU.hpp"
#include "Device/Barometer.hpp"

// Sensed Model
#include "Dynamics/PhysicalState.hpp"

namespace Dynamics
{
    namespace Sensing
    {

        class Sensors
        {
            PhysicalState sensedState;

            Device::Barometer baro;
            Device::IMU imu;

        public:
            /**
             * Initialises all sensors
             */
            bool init();

            /**
             * Reads sensor data from all available sensors
             */
            void update();

            /**
             * returns the most recent state from the sensors
             */
            PhysicalState getSensedState();

            /**
             * Reads the values from the gyroscope
             */
            PhysicalState readIMUData();

            /**
             * Reads the values from the accelerometer
             */
            PhysicalState readBaroData();

            /**
             * Lists the names and details of all connected sensors
             */
            String listAvailableSensors();

            // TODO: Show all connected devices, regardless of if connected/accounted for by this class)
        };

    } // namespace Sensing

} // namespace Dynamics

#endif /* SENSORS_HPP */