#ifndef HAL_H
#define HAL_H
#include "components.h"

#define digitalWrite(port,pin,state) pal_lld_writepad(port,pin,state)
#define digitalToggle(port,pin) pal_lld_togglepad(port,pin)
#endif