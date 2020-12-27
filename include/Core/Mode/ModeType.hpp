//
//  ModeType.hpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef MODE_TYPE_HPP
#define MODE_TYPE_HPP

namespace Core
{
    namespace Mode
    {
        enum ModeType
        {
            INITIALISE,
            IDLE,
            ARM,
            TAKEOFF,
            HOVER,
            LAND,
            TEST,
            SHUTDOWN,
        };
    } // namespace Mode
} // namespace Core

#endif /* MODE_TYPE_HPP */
