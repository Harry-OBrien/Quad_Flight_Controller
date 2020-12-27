//
//  PhysicalState.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef PHYSICAL_STATE_HPP
#define PHYSICAL_STATE_HPP

#include <Arduino.h>

namespace Dynamics
{
    /**
     * A structure to describe the physical state of the pod, whether that is a target state or a current state
     * 
     * Abbreviations:
     * s: dispacement (m)
     * v: velocity (m/s)
     * a: acceleration (m/s^2)
     * g: delta theta (rotational velocity) (radians/s)
     * mag: magtometer
     */
    struct PhysicalState
    {
        // TODO: Refactor to use vectors
        double sx, sy, sz;
        double distance;

        double vx, vy, vz;
        double speed;

        double ax, ay, az;
        double acceleration;

        double pitch, roll, yaw;
        double gx, gy, gz;

        double mx, my, mz;
        double heading;

        double altitude;
        double temperature;

        bool stateValid = true;

        /**
         * Default constructor. Zeros out all values on initialisation
         */
        PhysicalState();

        /**
         * produces details of this model as a string
         */
        String toString();
    };
} // namespace Dynamics

#endif /* PHYSICAL_STATE_HPP */