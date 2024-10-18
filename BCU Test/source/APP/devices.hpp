#ifndef _DEVICES_H
#define _DEVICES_H

#include "device_class.hpp"
#include "input_elements.h"
#include "syscalls.h"

Device* devices[MAX_CHANNELS];

//Device* devices[MAX_CHANNELS];

void create_devices() {
    // Initialize devices at runtime
    devices[0] = new momentary_Device(&channels[3], &hornButton, 1 , 5, 2000);
    devices[1] = new latch_Device(&channels[5], &lowbeamButton, 1,5,2000);
    devices[2] = new momentary_Device(&channels[4], &passButton, 1,5,2000);
    devices[3] = new toggle_Device(&channels[1], &leftButton, 1,5,2000);
    devices[4] = new toggle_Device(&channels[2], &rightButton, 1,5,2000);
    devices[5] = new latch_Device(&channels[0], &highbeamButton, 1,5,2000);
}       

#endif
