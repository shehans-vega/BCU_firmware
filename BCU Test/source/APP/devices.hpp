#ifndef _DEVICES_H
#define _DEVICES_H

#include "device_class.hpp"
#include "input_elements.h"
#include "syscalls.h"

#define  MAX_DEVICES 7

enum{
    horn,
    lbeam,
    pass,
    left,
    right,
    hbeam,
    pdu_fan
}device_ids;

Device* devices[MAX_DEVICES];

void create_devices() {
    // Initialize devices at runtime
    devices[horn] = new momentary_Device(&channels[3], &(buttons[HRN_BTN]), 10 , 15, 2000);
    devices[lbeam] = new latch_Device(&channels[0], &hbeam_btn, 10,15,2000);
    devices[pass] = new momentary_Device(&channels[5], &(buttons[PASS_BTN]), 10,15,2000);
    devices[left] = new toggle_Device(&channels[2], &(buttons[LEFT_BTN]), 10,15,2000);
    devices[right] = new toggle_Device(&channels[1], &(buttons[RGT_BTN]), 10,15,2000);
    devices[hbeam] = new momentary_Device(&channels[5], &hbeam_btn, 5,15,300);
    devices[pdu_fan] = new momentary_Device(&channels[4],&buttons[dummy_BTN], 5,15,300);
} 

#endif
