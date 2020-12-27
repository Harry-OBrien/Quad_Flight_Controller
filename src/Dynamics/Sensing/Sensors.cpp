//
//  Sensors.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Dynamics/Sensing/Sensors.hpp"
#include <Wire.h>

using namespace Dynamics;
using namespace Sensing;

/**
 * Initialises all sensors
 */
bool Sensors::init()
{
    Wire.begin();

    // return false if either sensor fails to initialise correctly
    bool success = true;
    success &= imu.initialise();
    // success &= baro.initialise();

    return success;
}

/**
 * Reads sensor data from all available sensors
 */
void Sensors::update()
{
    // Read sensor data
    PhysicalState model = readIMUData();
    PhysicalState baroData = readBaroData();

    model.altitude = baroData.altitude;
    model.temperature = baroData.temperature;

    // update the sensed model
    sensedState = model;
}

/**
 * returns the most recent state from the sensors
 */
PhysicalState Sensors::getSensedState()
{
    // TODO: Only update if sensor data is stale (x amount of time has passed since last reading)
    update();
    return sensedState;
}

/**
 * Reads the values from the gyroscope
 */
PhysicalState Sensors::readIMUData()
{
    return imu.getReading();
}

/**
 * Reads the values from the accelerometer
 */
PhysicalState Sensors::readBaroData()
{
    return baro.getReading();
}

/**
 * Lists the names and details of all connected sensors
 */
String Sensors::listAvailableSensors()
{
    //TODO: Implement
    return String("WARNING: listing all available sensors is currently not implemented");
}