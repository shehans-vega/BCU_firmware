#ifndef _MODULES_H
#define _MODULES_H

#include "module_class.hpp"
#include "devices.hpp"
#include <new>

HeadLight_Module* headlight_unit = nullptr;
TurnSignal_Module* turnsignal_unit = nullptr;
Horn_Module* horn_unit = nullptr;

void create_modules(){
   headlight_unit = new HeadLight_Module(devices[hbeam],devices[lbeam],devices[pass]);
   turnsignal_unit = new TurnSignal_Module(devices[left],devices[right]);
   horn_unit = new Horn_Module(devices[horn]);
}

#endif