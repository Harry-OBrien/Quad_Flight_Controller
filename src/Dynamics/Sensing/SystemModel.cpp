//
//  SystemModel.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 28/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Dynamics/Sensing/SystemModel.hpp"

using namespace Dynamics::Sensing;

SystemModel::SystemModel()
{
}

SystemModel::~SystemModel()
{
}

/**
 * Initialise the system model
 */
void SystemModel::init()
{
    if (!sensors.init())
    {
        Serial.println("At least one sensor failed to start... Shit.");
    }
}

/**
 * update the current model
 */
void SystemModel::update()
{
    // read the sensor data
    sensedState = sensors.getSensedState();

    //update our model
    float deltat = fusion.deltatUpdate();
    fusion.MadgwickUpdate(sensedState.gx,
                          sensedState.gy,
                          sensedState.gz,

                          sensedState.ax,
                          sensedState.ax,
                          sensedState.ax,

                          sensedState.mx,
                          sensedState.mx,
                          sensedState.mx,

                          deltat);

    estimatedState = sensedState;

    estimatedState.pitch = fusion.getPitch();
    estimatedState.roll = fusion.getRoll();
    estimatedState.yaw = fusion.getYaw();

    // complete acceleration vector
    estimatedState.acceleration = sqrt(sensedState.ax * sensedState.ax +
                                       sensedState.ay * sensedState.ay +
                                       sensedState.az * sensedState.az);

    // Update velocity
    estimatedState.vx += sensedState.ax * deltat;
    estimatedState.vy += sensedState.ay * deltat;
    estimatedState.vz += sensedState.az * deltat;
    estimatedState.speed = sqrt(sensedState.vx * sensedState.vx +
                                sensedState.vy * sensedState.vy +
                                sensedState.vz * sensedState.vz);

    // Update position
    estimatedState.sx += sensedState.vx * deltat;
    estimatedState.sy += sensedState.vy * deltat;
    estimatedState.sz += sensedState.vz * deltat;

    estimatedState.distance = sqrt(sensedState.sx * sensedState.sx +
                                   sensedState.sy * sensedState.sy +
                                   sensedState.sz * sensedState.sz);
}

/**
 * get the best estimate of the current physical state
 */
Dynamics::PhysicalState SystemModel::getEstimatedState()
{
    return estimatedState;
}

/**
 * get the most-recent sensed physical state
 */
Dynamics::PhysicalState SystemModel::getSensedState()
{
    return sensedState;
}