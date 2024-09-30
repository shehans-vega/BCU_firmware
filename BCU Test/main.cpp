

#include <vector>

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "APP/output_elements.h"
#include "devices.hpp"
#include "modules.hpp"
#include "syscalls.h"
#include "can.h"
 
uint8_t hl = false;

int main()
{
    
    componentsInit();
    irqIsrEnable();
    ADC_init();
    CAN_init();
    initialize_channels_from_config(pinconfig, channels);
    create_devices();
    create_modules();
    
    //highbeam_device.device_channel->channel_on_impl();
    for(;;){
    CAN_send();
    inputs();
    headlight_unit->activate();
    headlight_unit->highbeam->activate();
    headlight_unit->lowbeam->activate();
    headlight_unit->passbeam->activate();
    turnsignal_unit->activate();
    turnsignal_unit->leftsignal->activate();
    turnsignal_unit->rightsignal->activate();
    horn_unit->activate();
    horn_unit->horn->activate();
    osalThreadDelayMilliseconds(1);
    }
}