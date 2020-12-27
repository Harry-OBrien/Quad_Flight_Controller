//
//  Mode.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef MODE_HPP
#define MODE_HPP

#include <Arduino.h>

namespace Core
{
    class SystemController;

    namespace Mode
    {
        /**
         * Pure virtual class to define the behaviour of the system. Inhereted into other
         * modes, such as 'initialise', 'run' etc., which perform tasks relevant to their
         * name
         */
        class Mode
        {
        protected:
            SystemController *sysCtrl;

        public:
            Mode(SystemController *_sysCtrl) : sysCtrl(_sysCtrl)
            {
            }

            virtual ~Mode()
            {
            }

            /**
             * Initialise this mode
             */
            virtual bool init() = 0;

            /**
             * Executes the behaviour for this mode. Repeatedly called by SystemController.
             */
            virtual bool run() = 0;

            /**
             * Gets the name of the mode as a string
             */
            virtual String toString() = 0;
        };
    } // namespace Mode
} // namespace Core

#endif /* MODE_HPP */
