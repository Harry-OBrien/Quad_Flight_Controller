//
//  SystemController.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Core/SystemController.hpp"
#include "Core/Mode/ModeHeader.hpp"
#include <Arduino.h>

using namespace Core;

SystemController::SystemController() : activeMode(new Mode::ModeInitialise(this)),
                                       nextMode(nullptr),
                                       dynamics(Dynamics::getDynamicsControllerInstance())
{
}

void SystemController::init()
{
    //Initialise serial out to console
    Serial.begin(115200);

    // Test to see if everything's working correctly
    Serial.println("INFO: System controller is alive!");

    if (!activeMode->init())
        Serial.println("WARNING: Something went wrong on start up...");
}

void SystemController::run()
{
    // Get radio input
    // ...

    // See if we should transition to a new mode
    if (nextMode != nullptr)
        transitionToNextMode();

    // execute the defined behaviour for the current mode
    if (!activeMode->run())
        Serial.println("WARNING: Something went wrong on this loop!");

    //Execute motion commands
    dynamics.run();
}

// MARK:- Private methods

void SystemController::shouldTransitionToMode(Mode::ModeType newMode)
{
    switch (newMode)
    {
    case Mode::INITIALISE:
        nextMode = new Mode::ModeInitialise(this);
        break;
    case Mode::IDLE:
        nextMode = new Mode::ModeIdle(this);
        break;
    default:
        nextMode = new Mode::ModeIdle(this);
    }
}

/// Makes the transition to the next mode
void SystemController::transitionToNextMode()
{
    // delete active mode
    delete activeMode;

    // transition the 'next mode' to active mode
    activeMode = nextMode;
    nextMode = nullptr;

    // Initialise the new active mode
    bool initSuccess = activeMode->init();

    if (!initSuccess)
    {
        Serial.print("Failure in initialising ");
        Serial.println(activeMode->toString());
    }
    else
    {
        Serial.print("Entering");
        Serial.println(activeMode->toString());
    }
}

SystemController &Core::getSysCtrlInstance()
{
    static SystemController sysCtrl;
    return sysCtrl;
}
