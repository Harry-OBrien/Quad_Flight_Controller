//
//  IMU.cpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 28/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include "Dynamics/Sensing/Device/IMU.hpp"

using namespace Dynamics::Sensing::Device;

IMU::IMU()
{
    latestValidReading.stateValid = false;
}

IMU::~IMU()
{
}
/**
 * Initialises the IMU and validates that it is alive
 */
bool IMU::initialise()
{
    if (mpu9250.begin() != INV_SUCCESS)
    {
        Serial.println("Unable to communicate with MPU-9250");
        Serial.println("Check connections, and try again.");
        Serial.println();
        return false;
    }

    Serial.println("IMU Initialised successfully!");

    alive = true;

    // Enable all sensors:
    mpu9250.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);

    mpu9250.setGyroFSR(2000); // Set gyro to 2000 dps

    mpu9250.setAccelFSR(4); // Set accel to +/-4g
    // Note: the MPU-9250's magnetometer FSR is set at
    // +/- 4912 uT (micro-tesla's)

    mpu9250.setLPF(5); // Set LPF corner frequency to 5Hz

    mpu9250.setSampleRate(10); // Set sample rate to 10Hz

    mpu9250.setCompassSampleRate(10); // Set mag rate to 10Hz

    // Get the first reading
    updateLatestReading();

    // Initialisation complete!
    initialised = true;
    return true;
}

/**
 * Reads the latest data from the IMU
 */
Dynamics::PhysicalState IMU::getReading()
{

    if (!mpu9250.dataReady())
    {
        return latestValidReading;
    }

    updateLatestReading();
    latestValidReading.stateValid = true;

    return latestValidReading;
}

void IMU::updateLatestReading()
{
    mpu9250.update(UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS);

    latestValidReading.ax = mpu9250.calcAccel(mpu9250.ax);
    latestValidReading.ay = mpu9250.calcAccel(mpu9250.ay);
    latestValidReading.az = mpu9250.calcAccel(mpu9250.az);

    latestValidReading.gx = mpu9250.calcGyro(mpu9250.gx);
    latestValidReading.gy = mpu9250.calcGyro(mpu9250.gy);
    latestValidReading.gz = mpu9250.calcGyro(mpu9250.gz);

    latestValidReading.mx = mpu9250.calcMag(mpu9250.mx);
    latestValidReading.my = mpu9250.calcMag(mpu9250.my);
    latestValidReading.mz = mpu9250.calcMag(mpu9250.mz);
}