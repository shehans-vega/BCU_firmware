#include <stdint.h>
#include <stdio.h>
#include "board.h"
#include "board_config.h"


#define CHANNEL_ON(port, pin)     pal_lld_setpad(port, pin)
#define CHANNEL_OFF(port, pin)    pal_lld_clearpad(port, pin)

typedef struct Channel {
    uint8_t pin;                 // Pin number
    uint8_t port;                // Port number
    uint8_t default_state;       // Default state (0 or 1)
    uint8_t fault_flag;          // Fault flag (0 for no fault, 1 for fault)
    uint8_t hard_fault_counter;   // Counter for hard faults
} ChannelType;

// Function to turn the channel on (implementation based on the pin/port)
void channel_on_impl(ChannelType* channel) {
    pal_lld_setpad(channel->port, channel->pin);
}

// Function to turn the channel off (implementation based on the pin/port)
void channel_off_impl(ChannelType* channel) {
    pal_lld_clearpad(channel->port, channel->pin);
}

// Function to reset the latch
void latch_reset_impl(ChannelType* channel) {
    channel->fault_flag = 0;           // Reset fault flag
    channel->hard_fault_counter = 0;   // Reset hard fault counter
    }

void init_channels_from_config(ChannelType* channels, pinconfigType* config) {
    for (int i = 0; i < MAX_CHANNELS; i++) {
        channels[i].pin = config->pins[i];  // Set pin from config
        channels[i].port = config->ports[i]; // Set port from config
        channels[i].default_state = config->default_states[i]; // Set default state
        channels[i].fault_flag = 0;          // Initialize fault flag to 0
        channels[i].hard_fault_counter = 0;  // Initialize hard fault counter to 0

        // Set function pointers for channel actions
        if  (channels[i].default_state == 0){
        	channel_off_impl(&channels[i]);
        }
        else{
        	channel_on_impl(&channels[i]);
                }
    }
}

