

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "MCAL/output_elements.h"

int main(){
   
    componentsInit();
    irqIsrEnable();
    ADC_init();
    init_channels_from_config(hschannels, &pinconfig);
    for(;;){
        channel_on_impl(&hschannels[4]);
        osalThreadDelayMilliseconds(500);
        channel_off_impl(&hschannels[4]);
        pal_lld_togglepad(PORT_LED1,LED1);
        pal_lld_togglepad(PORT_LED2,LED2);
        osalThreadDelayMilliseconds(500);

    }
}