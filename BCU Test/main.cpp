

#include "components.h"
#include "adc_driver.h"
#include "board_config.h"
#include "gpio_interface.h"


int main(){
   
    componentsInit();
    irqIsrEnable();
    ADC_init();
    for(;;){
        pal_lld_togglepad(PORT_LED1,LED1);
        pal_lld_togglepad(PORT_LED2,LED2);
         osalThreadDelayMilliseconds(500);

    }
}