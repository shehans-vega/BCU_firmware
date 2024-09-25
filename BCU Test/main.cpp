

#include <vector>

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "APP/output_elements.h"
#include "devices.hpp"


int main()
{
    
    componentsInit();
    irqIsrEnable();
    ADC_init();
    
    initialize_channels_from_config(pinconfig, channels);
     
    create_devices();
    //highbeam_device.device_channel->channel_on_impl();
    for(;;){
   //highbeam_device.device_channel->channel_on_impl(); 
   //channels[4].channel_on_impl();  // pal_lld_togglepad(PORT_LED1,LED1);
    // pal_lld_togglepad(PORT_LED2,LED2);
    osalThreadDelayMilliseconds(500);
    }
}
