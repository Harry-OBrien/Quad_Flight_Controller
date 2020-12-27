//
//  Radio.cpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include "Communication/Radio.hpp"

using namespace Coms;

Radio::Radio() : receiverInterface(Serial5)
{
}

bool Radio::init()
{
    receiverInterface.begin();
    return true;
}

void Radio::update()
{
    if (receiverInterface.read(&channels[0], &failSafe, &lostFrame))
    {
        printMessage();
    }
}

uint16_t *Radio::getLatestPacket()
{
    // TODO: update latest packet if too old
    // TODO: Make thread safe
    return &channels[0];
}

void Radio::printMessage()
{
    update();

    Serial.println("Msg from receiver:");
    for (size_t i = 0; i < 8; i++)
    {
        Serial.print(i);
        Serial.print(": ");
        Serial.println(channels[i]);
    }

    Serial.println();
}