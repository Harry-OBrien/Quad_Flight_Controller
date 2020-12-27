//
//  SystemController.hpp
//  Hyperloop_Embedded
//
//  Created by Harry O'Brien on 22/05/2020.
//  Copyright © 2020 Hyperloop Manchester. All rights reserved.
//

#ifndef SYSTEM_CONTROLLER_HPP
#define SYSTEM_CONTROLLER_HPP

#include "Mode/Mode.hpp"
#include "Mode/ModeType.hpp"
#include "Dynamics/DynamicsController.hpp"

namespace Core
{
   /**
     *  The SystemController class is the controller of the whole system. All other classes
     *  are typically stagnant until the controller requests from, or pushes data to
     *  them.
     *
     *  This class is a singleton meaning only 1 instance of it exists in memory at any
     *  one time. We use the extern function 'getSystemCtrl()' to get the instance of this
     *  class.
     */
   class SystemController;
   extern SystemController &getSysCtrlInstance();

   namespace Mode
   {
      class ModeInitialise;
      class ModeIdle;
      class ModeArm;
   } // namespace Mode

   /**
    * The system controller is the master controller for the entire system
    */
   class SystemController
   {
      // The different modes are sub-components of the system controller and are allowed to access private methods and vars
      friend Mode::ModeInitialise;
      friend Mode::ModeIdle;
      friend Mode::ModeArm;

      Mode::Mode *activeMode;
      Mode::Mode *nextMode;

      bool initialised = false;

      //Dynamics controller
      Dynamics::DynamicsController &dynamics;

   public:
      /**
       *  This method initialises the system. It MUST be called before 'run' is executed.
       */
      void init();

      /**
       *  This method should only ever be called forever from a permanent loop in main. This is the
       *  entry point to the normal flow of the program.
       */
      void run();

      /**
       * Dissalow construction from another instance; Singleton class
       */
      SystemController(SystemController const &) = delete;

      /**
       * Delete copy constructor; Singleton class
       */
      void operator=(SystemController const &) = delete;

   private:
      /**
       *  Private constructor; Singleton class
       */
      SystemController();

      /**
       *  Check for whether system is initialised yet.
       */
      bool isInitialised() { return initialised; }

      /**
       * Informs the controller that we should transition to the given mode next.
       */
      void shouldTransitionToMode(Mode::ModeType newMode);

      /**
       * Makes the transition to the next mode
       */
      void transitionToNextMode();

      /**
       *  Friend function to get the instance of the system controller. Note that since this class is
       *  designed to be a singleton, only 1 instance will ever exist in memory at any 1 time.
       */
      friend SystemController &getSysCtrlInstance();
   };
} // namespace Core

#include "Core/Mode/ModeHeader.hpp"

#endif /* SYSTEM_CONTROLLER_HPP */