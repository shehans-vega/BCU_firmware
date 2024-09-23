#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#include "board.h"
#include "MCAL/board_config.h"
#include "components.h"
#include <vector>

// Define the Channel class
class Channel {
private:
    pinconfigType* pins;  // Pointer to pinconfigType

public:
    bool fault_flag;
    uint8_t hard_fault_counter;

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
};

// void init_channels_from_config(std::vector<Channel>& vec, pinconfigType config) {
//     // Resize the vector to hold the maximum number of channels
//     vec.resize(MAX_CHANNELS);

//     // Initialize each Channel using the provided pin configurations
//     for (int i = 0; i < MAX_CHANNELS; i++) {
//         // Create Channel objects using the configPtr
//         vec.emplace_back(config[i]); // Pass the pointer to the specific pinconfigType
//     }
// }

#endif
