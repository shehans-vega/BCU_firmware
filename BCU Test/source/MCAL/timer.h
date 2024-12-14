#ifndef TIMER_H
#define TIMER_H

#include "components.h"

//Standalone delay function
bool pseudo_delay(unsigned long interval) {
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = osalThreadGetMilliseconds();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        return true;
    }
    return false;
}
// delay function with an explicit previousMillis parameter // used function overloading feature
bool pseudo_delay(unsigned long interval, unsigned long &previousMillis) {
    unsigned long currentMillis = osalThreadGetMilliseconds();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        return true;
    }
    return false;
}

#endif