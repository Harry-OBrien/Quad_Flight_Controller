//
//  SystemModel.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 28/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef SYSTEM_MODEL_HPP
#define SYSTEM_MODEL_HPP

#include <SensorFusion.hpp>

#include "Dynamics/Sensing/SystemModel.hpp"
#include "Dynamics/PhysicalState.hpp"
#include "Sensors.hpp"

namespace Dynamics
{
    namespace Sensing
    {
        /**
         * A model that is able to use sensed values to create a best estimate of the current
         * physical state of the system. Uses multiple sensors and a kalman filter to generate
         * this estimate
         */
        class SystemModel
        {
            PhysicalState estimatedState;
            PhysicalState sensedState;

            SF fusion;

            Sensors sensors;

            float lastUpdate = 0;

        public:
            SystemModel();

            ~SystemModel();

            /**
             * Initialise the system model
             */
            void init();

            /**
             * update the current model
             */
            void update();

            /**
             * get the best estimate of the current physical state
             */
            PhysicalState getEstimatedState();

            /**
             * get the most-recent sensed physical state
             */
            PhysicalState getSensedState();
        };
    } // namespace Sensing

} // namespace Dynamics

#endif /* SYSTEM_MODEL_HPP */