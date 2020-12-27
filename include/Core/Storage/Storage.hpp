//
//  storage.hpp
//  QuadcopterFlightController
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <Arduino.h>

namespace Core
{
    namespace Storage
    {
        template <typename T>
        bool saveObjectToFlash(T obj, int location)
        {
            return false;
        }

        template <typename T>
        T readObjectFromFlash(int location)
        {
            return T();
        }

        template <typename T>
        bool saveObjectToSD(T obj, String filename)
        {
            return false;
        }

        template <typename T>
        T saveObjectToFlash(int location)
        {
            return T();
        }
    } // namespace Storage
} // namespace Core
#endif /* STORAGE_HPP */
