//
//  ModeIdle.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Core/Mode/ModeIdle.hpp"

using namespace Core;
using namespace Mode;

ModeIdle::ModeIdle(Core::SystemController *sysCtrl) : Mode(sysCtrl)
{
}

ModeIdle::~ModeIdle()
{
}

bool ModeIdle::init()
{
    Serial.println("INFO: Entering idle mode!");
    sysCtrl->dynamics.enterIdle();

    return true;
}

bool ModeIdle::run()
{
    if (millis() - millisLastUpdatedSensors > updateSensorPeriod)
    {
        // Print sensor readings
        Serial.println("INFO: Most recent readings: ");
        Serial.println(sysCtrl->dynamics.getEstimatedState().toString());

        millisLastUpdatedSensors = millis();
    }

    // Look for radio to arm the quad
    // ...

    return true;
}

String ModeIdle::toString()
{
    return "Mode Idle";
}