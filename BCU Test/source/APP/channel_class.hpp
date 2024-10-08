#ifndef _CHANNEL_CLASS_H
#define _CHANNEL_CLASS_H

#include "board.h"
#include "MCAL/board_config.h"
#include "adc_driver.h"
#include "components.h"


// Define the Channel class
class Channel {
private:
    pinconfigType* pins;  // Pointer to pinconfigType

public:
    bool fault_flag;
    uint8_t hard_fault_counter;

   // Default Constructor
    Channel() : pins(nullptr), fault_flag(false), hard_fault_counter(0) {}
 // Constructor to initialize Channel using a pointer to a pinconfigType object
    Channel(pinconfigType* config) 
        : pins(config), fault_flag(false), hard_fault_counter(0) {}

    void channel_on_impl() {
        if (pins) {  // Check if pins is not null
            pal_lld_setpad(this->pins->gpio.port, this->pins->gpio.pin);
        }
    }

    void channel_off_impl() {
        if (pins) {  // Check if pins is not null
            pal_lld_clearpad(this->pins->gpio.port, this->pins->gpio.pin);
        }
    }

    void latch_reset_impl() {
        this->fault_flag = false;         // Reset fault flag
        this->hard_fault_counter = 0;     // Reset hard fault counter
    }

    void diagnose_en_impl() {
        if (pins && this->pins->den == 1) {  // Check if pins is not null
            pal_lld_setpad(this->pins->dns_pins.port, this->pins->dns_pins.pin);
            if (this->pins->dsel == 1) {
                pal_lld_setpad(this->pins->dsel_pins.port, this->pins->dsel_pins.pin);
            } else {
                pal_lld_clearpad(this->pins->dsel_pins.port, this->pins->dsel_pins.pin);
            }
        } else {
            if (pins) {  // Check if pins is not null
                pal_lld_clearpad(this->pins->dns_pins.port, this->pins->dns_pins.pin);
            }
        }
    }
    uint16_t diagnose(void);
};

uint16_t Channel::diagnose(void){
    diagnose_en_impl();
    uint16_t current = adc_value[this->pins->adc_channel];
    return current;
}

void initialize_channels_from_config(pinconfigType* configs, Channel* channels) {
    for ( int i = 0; i < MAX_CHANNELS; ++i) {
        // Initialize each Channel with the corresponding pinconfigType
        channels[i] = Channel(&configs[i]);  // Use the parameterized constructor
    }
}

#endif
