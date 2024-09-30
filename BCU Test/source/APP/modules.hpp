#ifndef _MODULES_H
#define _MODULES_H

#include "module_class.hpp"
#include "devices.hpp"
#include <new>

HeadLight_Module* headlight_unit = nullptr;
TurnSignal_Module* turnsignal_unit = nullptr;

void create_modules(){
   headlight_unit = new HeadLight_Module(devices[5],devices[1],devices[2]);
   turnsignal_unit = new TurnSignal_Module(devices[3],devices[4]);

}

#endif