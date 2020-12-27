//
//  PhysicalState.cpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#include "Dynamics/PhysicalState.hpp"

using namespace Dynamics;

PhysicalState::PhysicalState() : sx(0), sy(0), sz(0), distance(0),
                                 vx(0), vy(0), vz(0), speed(0),
                                 ax(0), ay(0), az(0), acceleration(0),
                                 pitch(0), roll(0), yaw(0),
                                 gx(0), gy(0), gz(0),
                                 mx(0), my(0), mz(0), heading(0),
                                 altitude(0),
                                 temperature(0),
                                 stateValid(true)
{
}

String PhysicalState::toString()
{
    String result;
    result += String("Reading is valid: ") + String(stateValid ? "True" : "False");
    result += String("\n");

    result += String("sx: ") + String(sx);
    result += String("\tsy: ") + String(sy);
    result += String("\tsz: ") + String(sz);
    result += String("\n");

    result += String("Distance Travelled: ") + String(distance);
    result += String("\n");

    result += String("vx: ") + String(vx);
    result += String("\tvy: ") + String(vy);
    result += String("\tvz: ") + String(vz);
    result += String("\n");

    result += String("Speed: ") + String(speed);
    result += String("\n");

    result += String("ax: ") + String(ax);
    result += String("\tay: ") + String(ay);
    result += String("\taz: ") + String(az);
    result += String("\n");

    result += String("Acceleration: ") + String(acceleration);
    result += String("\n");

    result += String("pitch: ") + String(pitch);
    result += String("\troll: ") + String(roll);
    result += String("\tyaw: ") + String(yaw);
    result += String("\n");

    result += String("gx: ") + String(gx);
    result += String("\tgy: ") + String(gy);
    result += String("\tgz: ") + String(gz);
    result += String("\n");

    result += String("mx: ") + String(mx);
    result += String("\tmy: ") + String(my);
    result += String("\tmz: ") + String(mz);
    result += String("\n");

    result += String("Heading: ") + String(heading);
    result += String("\n");

    result += String("Altitude: ") + String(altitude);
    result += String("\n");

    result += String("Temperature: ") + String(temperature);
    result += String("\n");

    return result;
}