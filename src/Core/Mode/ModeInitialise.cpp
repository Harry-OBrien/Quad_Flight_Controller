//
//  ModeInitialise.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Core/Mode/ModeInitialise.hpp"

using namespace Core;
using namespace Mode;

ModeInitialise::ModeInitialise(Core::SystemController *sysCtrl) : Mode(sysCtrl)
{
}

ModeInitialise::~ModeInitialise()
{
}

bool ModeInitialise::init()
{
    // initialise sensors
    Serial.println("Initialising sensors...");
    sysCtrl->dynamics.init();

    // calibrate sensors
    Serial.println("Calibrating sensors...");
    sysCtrl->dynamics.calibrate();

    // Request tansition to idle
    sysCtrl->shouldTransitionToMode(IDLE);

    // Done!
    Serial.println("Initialisation complete!");
    sysCtrl->initialised = true;
    return true;
}

bool ModeInitialise::run()
{
    return true;
}

String ModeInitialise::toString()
{
    return "Mode Initialise";
}