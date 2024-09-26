

#include <vector>

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "APP/output_elements.h"
#include "devices.hpp"
#include "syscalls.h"


int main()
{
    
    componentsInit();
    irqIsrEnable();
    ADC_init();
    
    initialize_channels_from_config(pinconfig, channels);

    create_devices();
    devices[2]->device_button->buttonState = BUTTON_PRESSED;
    
    //highbeam_device.device_channel->channel_on_impl();
    for(;;){
        devices[2]->activate();
   //highbeam_device.device_channel->channel_on_impl(); 
   //channels[4].channel_on_impl();  // pal_lld_togglepad(PORT_LED1,LED1);
    // pal_lld_togglepad(PORT_LED2,LED2);
    osalThreadDelayMilliseconds(500);
    }
}
