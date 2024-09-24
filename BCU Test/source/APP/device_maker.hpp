#ifndef _DEVICE_MAKER_H
#define _DEVICE_MAKER_H

#include "gpio_interface.hpp"
#include "input_elements.h"
#include "output_elements.h"

#define highbeam_current 1
#define lowbeam_current 1
class Device{

    private:
  
    public:
        Channel* device_channel;
        buttonInput_t* device_button;
        uint8_t max_current;

        Device();
        Device(Channel* channel, buttonInput_t* button,uint8_t current): device_channel(channel),device_button(button),max_current(current){};

    bool fault;
    };

#endif


