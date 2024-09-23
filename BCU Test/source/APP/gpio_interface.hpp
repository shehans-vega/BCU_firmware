#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#include "board.h"
#include "MCAL/board_config.h"
#include "components.h"
#include <vector>

class Channel
{
private:
    
public:
    pinconfigType* pins;
    bool fault_flag;
    uint8_t hard_fault_counter;
   
    Channel(pinconfigType* config)
    {
        pins = config;
        fault_flag = false;
        hard_fault_counter = 0;
    }

    void channel_on_impl()
    {
        pal_lld_setpad(this->pins->gpio.port, this->pins->gpio.pin);
    }

    void channel_off_impl()
    {
        pal_lld_clearpad(this->pins->gpio.port, this->pins->gpio.pin);
    }

    void latch_reset_impl()
    {
        this->fault_flag = false;         // Reset fault flag
        this->hard_fault_counter = 0;     // Reset hard fault counter
    }

    void diagnose_en_impl()
    {
        if (this->pins->den == 1)
        {
            pal_lld_setpad(this->pins->dns_pins.port, this->pins->dns_pins.pin);
            if (this->pins->dsel == 1)
            {
                pal_lld_setpad(this->pins->dsel_pins.port, this->pins->dsel_pins.pin);
            }
            else
            {
                pal_lld_clearpad(this->pins->dsel_pins.port, this->pins->dsel_pins.pin);
            }
        }
        else
        {
            pal_lld_clearpad(this->pins->dns_pins.port, this->pins->dns_pins.pin);
        }
    }
};

// // Initialize channels from the config array
// void init_channels_from_config(std::vector<Channel>& channels, const pinconfigType* config) {
//     channels.resize(MAX_CHANNELS);
//     for (int i = 0; i < MAX_CHANNELS; i++) {
//         channels[i] = Channel(&config[i]);
//     }
// }

#endif