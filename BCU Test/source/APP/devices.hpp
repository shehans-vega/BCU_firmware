#ifndef _DEVICES_H
#define _DEVICES_H

#include "device_class.hpp"
#include "input_elements.h"
#include "syscalls.h"

Device* devices[MAX_CHANNELS];

//Device* devices[MAX_CHANNELS];

void create_devices() {
    // Initialize devices at runtime
    devices[0] = new latch_Device(&channels[4], &hornButton, 1);
    devices[1] = new momentary_Device(&channels[5], &lowbeamButton, 1);
    devices[2] = new momentary_Device(&channels[2], &passButton, 1);
    devices[3] = new toggle_Device(&channels[1], &leftButton, 1);
    devices[4] = new toggle_Device(&channels[3], &rightButton, 1);
    devices[5] = new momentary_Device(&channels[0], &highbeamButton, 1);
}

#endif
