

#include <vector>

#include "components.h"
#include "MCAL/adc_driver.h"
#include "MCAL/board_config.h"
#include "APP/gpio_interface.hpp"
#include "MCAL/output_elements.h"

Channel channels[MAX_CHANNELS];
int main()
{

    componentsInit();
    irqIsrEnable();
    ADC_init();
    initialize_channels_from_config(pinconfig, channels);
    channels[0].channel_on_impl();
    channels[1].channel_on_impl();
    channels[2].channel_on_impl();
    channels[3].channel_on_impl();
    channels[4].channel_on_impl();
    channels[5].channel_on_impl();
    // pal_lld_togglepad(PORT_LED1,LED1);
    // pal_lld_togglepad(PORT_LED2,LED2);
    osalThreadDelayMilliseconds(500);
    //  channels.emplace_back(&pinconfig[5]);
}
