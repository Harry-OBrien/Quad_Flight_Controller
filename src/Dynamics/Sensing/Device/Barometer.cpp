//
//  Barometer.cpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 28/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include "Dynamics/Sensing/Device/Barometer.hpp"

using namespace Dynamics::Sensing::Device;

Barometer::Barometer()
{
}

Barometer::~Barometer()
{
}

/**
 * Initialised the barometer and validates that it is alive
 */
bool Barometer::initialise()
{
    if (!bmp.begin())
    {
        Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
        return false;
    }

    alive = true;

    /* Default settings from datasheet. */
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

    // Initialisation Complete!
    initialised = true;

    return true;
}

/**
 * Reads the latest data from the barometer
 */
Dynamics::PhysicalState Barometer::getReading()
{
    PhysicalState reading;
    reading.temperature = bmp.readTemperature();
    reading.altitude = bmp.readAltitude(referencePressure);

    return reading;
}