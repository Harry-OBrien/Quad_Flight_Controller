//
//  DynamicsController.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Dynamics/DynamicsController.hpp"

using namespace Dynamics;

DynamicsController::DynamicsController()
{
}

bool DynamicsController::init()
{
    model.init();
}

void DynamicsController::calibrate()
{
    // TODO: Implement
}

void DynamicsController::run()
{
    // update the model
    model.update();

    //retrieve the current estimate of the system
    PhysicalState currentState = model.getEstimatedState();

    //update the segment planner and tracking controller
    // ...

    // Handle any callbacks
    // ...
}

/**
 * Sets the maximum speed of the pod
 */
void DynamicsController::setMaxSpeed(double _maxSpeed)
{
    maxSpeed = _maxSpeed;
}

/**
 * Gets the currently active maximum speed of the pod
 */
double DynamicsController::getMaxSpeed()
{
    return maxSpeed;
}

/**
 * Sets the maximum acceleration of the pod
 */
void DynamicsController::setMaxAcceleration(double _maxAcceleration)
{
    maxAcceleration = _maxAcceleration;
}

/**
 * Gets the currently active maximum acceleration of the pod
 */
double DynamicsController::getMaxAcceleration()
{
    return maxAcceleration;
}

/**
 * Sets the target state that the pod should try to move to
 */
void DynamicsController::setTargetState(PhysicalState target)
{
    targetState = target;
}

/**
 * Gets the currently set state distance that the pod should try to move to
 */
PhysicalState DynamicsController::getTargetState()
{
    return targetState;
}

/**
 * Force the system to perform an emergency top
 */
void DynamicsController::emergencyStop()
{
    allowedToContinue = false;
    emergencyStopActive = true;
}

PhysicalState DynamicsController::getSensedState()
{
    return model.getSensedState();
}

PhysicalState DynamicsController::getEstimatedState()
{
    return model.getEstimatedState();
}

void DynamicsController::arm()
{
    armed = true;
    allowedToContinue = true;

    trackingCtrl.setAlive(true);
}

void DynamicsController::enterIdle()
{
    armed = false;
    allowedToContinue = false;

    trackingCtrl.setAlive(false);
}

DynamicsController &Dynamics::getDynamicsControllerInstance()
{
    static DynamicsController dynCtrl;
    return dynCtrl;
}