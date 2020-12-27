#include <Arduino.h>
#include "Core/SystemController.hpp"

void setup()
{
  delay(5000);
}

void loop()
{
  // Get the singleton instance of the system controller and initialise
  Core::SystemController &sysCtrl = Core::getSysCtrlInstance();
  sysCtrl.init();

  // Run the system controller forever
  while (true)
    sysCtrl.run();

  // We should never reach this point, but if we do, hold here forever.
  while (true)
    ;
}
