

#include <vector>

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
    // channel5.channel_on_impl();

   std::vector<Channel> channels;
    channels.emplace_back(channel5); // Make sure Channel is copyable
       
        // pal_lld_togglepad(PORT_LED1,LED1);
        // pal_lld_togglepad(PORT_LED2,LED2);
        osalThreadDelayMilliseconds(500);
      //  channels.emplace_back(&pinconfig[5]);
}
