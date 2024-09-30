

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

    
    //devices[0]->device_channel->channel_on_impl();
    
    // headlight_unit->highbeam->device_channel->channel_on_impl();
    // hl = headlight_unit->highbeam->device_button->buttonState;
    
       /// devices[2]->activate();
   //highbeam_device.device_channel->channel_on_impl(); 
   //channels[4].channel_on_impl();  // pal_lld_togglepad(PORT_LED1,LED1);
    // pal_lld_togglepad(PORT_LED2,LED2);
    osalThreadDelayMilliseconds(1);
    }
}