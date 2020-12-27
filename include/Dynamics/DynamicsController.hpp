//
//  DynamicsController.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef DYNAMICS_CONTROLLER_HPP
#define DYNAMICS_CONTROLLER_HPP

#include "PhysicalState.hpp"
#include "Sensing/SystemModel.hpp"
#include "Motion/SegmentPlanner.hpp"
#include "Motion/TrackingController.hpp"

namespace Dynamics
{
    class DynamicsController;
    extern DynamicsController &getDynamicsControllerInstance();

    /**
     * Controller for all things that move (and detect things that move)
     */
    class DynamicsController
    {
        Sensing::SystemModel model;
        Motion::SegmentPlanner segPlanner;
        Motion::TrackingController trackingCtrl;

        double maxSpeed = 0;
        double maxAcceleration = 0;
        PhysicalState targetState;

        bool armed = false;
        bool allowedToContinue = false;
        bool emergencyStopActive = false;

        int const initialMotorSpeed = 8;

    public:
        bool init();

        void calibrate();

        void run();

        /**
         *  Dissalow construction from another instance; Singleton class
         */
        DynamicsController(DynamicsController const &) = delete;

        /**
         * Delete copy constructor; Singleton class
         */
        void operator=(DynamicsController const &) = delete;

        /**
         * Sets the maximum speed of the pod
         */
        void setMaxSpeed(double _maxSpeed);

        /**
         * Gets the currently active maximum speed of the pod
         */
        double getMaxSpeed();

        /**
         * Sets the maximum acceleration of the pod
         */
        void setMaxAcceleration(double _maxAcceleration);

        /**
         * Gets the currently active maximum acceleration of the pod
         */
        double getMaxAcceleration();

        /**
         * Sets the target distance that the pod should try to move to
         */
        void setTargetState(PhysicalState target);

        /**
         * Gets the currently set target distance that the pod should try to move to
         */
        PhysicalState getTargetState();

        /**
         * Force the system to perform an emergency stop
         */
        void emergencyStop();

        PhysicalState getSensedState();

        PhysicalState getEstimatedState();

        void arm();

        void enterIdle();

    private:
        /**
         * Private constructor; singleton class
         */
        DynamicsController();

        /**
         *  Friend function to get the instance of the dynamics controller. Note that since this class is
         *  designed to be a singleton, only 1 instance will ever exist in memory at any 1 time.
         */
        friend DynamicsController &getDynamicsControllerInstance();
    };
} // namespace Dynamics

#endif /* DYNAMICS_CONTROLLER_HPP */