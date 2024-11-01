

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

#include "hal.h"
#include "timer.h"

uint8_t hl = false;
uint32_t timedebug = 0;

int main()
{
    componentsInit();
    irqIsrEnable();
    digitalWrite(switcharm.port,switcharm.pin, 1);
    ADC_init();
    CAN_init();
    initialize_channels_from_config(pinconfig, channels);
    create_devices();
    create_modules();
    
    for(;;){
    if(pseudo_delay(50)){
    digitalToggle(onboardLED[0].port,onboardLED[0].pin);}
    timedebug = osalThreadGetMilliseconds();
    if(osalThreadGetMilliseconds()>=2000){
    digitalWrite(switcharm.port,switcharm.pin, 0);
    }
    CAN_send();
    inputs();
    headlight_unit->activate();
    turnsignal_unit->activate();
    horn_unit->activate();
    osalThreadDelayMicroseconds(1);
    }
}
