//
//  TrackingController.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef TRACKING_CONTROLLER_HPP
#define TRACKING_CONTROLLER_HPP

#include <Arduino.h>
#include <Servo.h>

namespace Dynamics
{
    namespace Motion
    {
        class TrackingController
        {
            Servo motor1, motor2, motor3, motor4;

            uint8_t const minimumMotorSpeed = 12; //percent

            bool alive = false;

        public:
            TrackingController()
            {
                motor1.attach(2);
                motor2.attach(3);
                motor3.attach(4);
                motor4.attach(5);
            }

            void setAlive(bool state)
            {
                alive = state;

                // Stop the motors if not alive
                if (!alive)
                {
                    motor1.writeMicroseconds(1000);
                    motor2.writeMicroseconds(1000);
                    motor3.writeMicroseconds(1000);
                    motor4.writeMicroseconds(1000);
                }
            }

            bool isAlive()
            {
                return alive;
            }

            void run()
            {
                // Don't perform any actions unless we are 'alive'
                if (!alive)
                    return;

                int throttle = map(minimumMotorSpeed, 0, 100, 1000, 2000);

                motor1.writeMicroseconds(throttle);
                motor2.writeMicroseconds(throttle);
                motor3.writeMicroseconds(throttle);
                motor4.writeMicroseconds(throttle);
            }
        };
    } // namespace Motion
} // namespace Dynamics

#endif /* TRACKING_CONTROLLER_HPP */