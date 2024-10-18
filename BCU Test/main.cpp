

#include <vector>

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/channel_class.hpp"
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
    for(;;){
    CAN_send();
    inputs();
    headlight_unit->activate();
    turnsignal_unit->activate();
    horn_unit->activate();
    osalThreadDelayMicroseconds(1);
    }
}
