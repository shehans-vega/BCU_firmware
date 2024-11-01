#ifndef TIMER_H
#define TIMER_H

#include "components.h"

bool pseudo_delay(unsigned long interval){
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = osalThreadGetMilliseconds();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update to the current time
        return true;
  }
  else {
    return false;
  }
}

#endif