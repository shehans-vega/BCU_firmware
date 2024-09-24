#ifndef _DEVICES_H
#define _DEVICES_H

#include "device_maker.hpp"
#include "input_elements.h"

extern Device devices[MAX_CHANNELS];
Device devices[MAX_CHANNELS];
//Device* devices[MAX_CHANNELS];

void create_devices(){

 Device highbeam_device(&channels[4],&highbeamButton,1);
 Device lowbeam_device(&channels[5],&lowbeamButton,1);
 Device passbeam_device(&channels[2],&passButton,1);
 Device leftsignal_device(&channels[1],&leftButton,1);
 Device rightsignal_device(&channels[3],&rightButton,1);
 Device horn_device(&channels[0],&hornButton,1);

devices[0] = highbeam_device;
devices[1] = lowbeam_device;
devices[2] = passbeam_device;
devices[3] = leftsignal_device;
devices[4] = rightsignal_device;
devices[5] = horn_device;
}
#endif
