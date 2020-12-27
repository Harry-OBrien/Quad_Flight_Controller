//
//  ModeIdle.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Core/Mode/ModeArm.hpp"

using namespace Core;
using namespace Mode;

ModeArm::ModeArm(Core::SystemController *sysCtrl) : Mode(sysCtrl)
{
}

ModeArm::~ModeArm()
{
}

bool ModeArm::init()
{
    // Validate all sensors are alive and initialised

    //spin up motors to 8% [initialMotorSpeed]
    sysCtrl->dynamics.arm();
    return true;
}

bool ModeArm::run()
{
    //Spin up motors to a low speed

    return true;
}

String ModeArm::toString()
{
    return "Mode Arm";
}