

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "MCAL/output_elements.h"

int main(){
   
    componentsInit();
    irqIsrEnable();
    ADC_init();
    Channel channel5(&pinconfig[5]);
    channel5.channel_on_impl();

   // init_channels_from_config(hschannels, &pinconfig);
    for(;;){
       
       
        // pal_lld_togglepad(PORT_LED1,LED1);
        // pal_lld_togglepad(PORT_LED2,LED2);
        osalThreadDelayMilliseconds(500);

    }
}