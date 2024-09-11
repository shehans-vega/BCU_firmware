
#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

#include <stdint.h>
#include <stdio.h>
#include "board.h"
#include "board_config.h"
#include "string.h"


#define CHANNEL_ON(port, pin)     pal_lld_setpad(port, pin)
#define CHANNEL_OFF(port, pin)    pal_lld_clearpad(port, pin)

typedef struct Channel {
    gpioType gpio;
    uint8_t default_state;       // Default state (0 or 1)
    uint8_t fault_flag;          // Fault flag (0 for no fault, 1 for fault)
    uint8_t hard_fault_counter;   // Counter for hard faults
    diagnoseType diagnose;
} ChannelType;


//Function to control gpio
void gpio_control(gpioType* gpio, char cmd[]  ){
	if(strcmp(cmd, "ON") == 0) {pal_lld_setpad(gpio->port, gpio->pin);}
	else if(strcmp(cmd, "OFF")==0){pal_lld_clearpad(gpio->port, gpio->pin);}
	else if(strcmp(cmd, "TOGGLE")==0){pal_lld_togglepad(gpio->port, gpio->pin);}
	else{}
}

// Function to turn the channel on (implementation based on the pin/port)
void channel_on_impl(ChannelType* channel) {
    pal_lld_setpad(channel->gpio.port, channel->gpio.pin);
}

// Function to turn the channel off (implementation based on the pin/port)
void channel_off_impl(ChannelType* channel) {
    pal_lld_clearpad(channel->gpio.port, channel->gpio.pin);
}
// Function to reset the latch
void latch_reset_impl(ChannelType* channel) {
    channel->fault_flag = 0;           // Reset fault flag
    channel->hard_fault_counter = 0;   // Reset hard fault counter
    }
void diagnose_en_impl(ChannelType* channel) {
    if(channel->diagnose.den ==1){
    	pal_lld_setpad(channel->diagnose.dns_pins.port, channel->diagnose.dns_pins.pin);
    	if(channel->diagnose.dsel ==1){
    	       	pal_lld_setpad(channel->diagnose.dsel_pins.port, channel->diagnose.dsel_pins.pin);
    	       }
    	       else{
    	       	pal_lld_clearpad(channel->diagnose.dsel_pins.port, channel->diagnose.dsel_pins.pin);
    	       }
    }
    else{
    	pal_lld_clearpad(channel->diagnose.dns_pins.port, channel->diagnose.dns_pins.pin);
    }
}

void init_channel(ChannelType* channel){
	  if  (channel->default_state == 0){
	        	channel_off_impl(channel);
	        }
	        else{
	        	channel_on_impl(channel);
	                }
}

void init_channels_from_config(ChannelType* channels, pinconfigType* config) {
    for (int i = 0; i < MAX_CHANNELS; i++) {
        channels[i].gpio.pin = config->gpio[i].pin;  // Set pin from config
        channels[i].gpio.port = config->gpio[i].port; // Set port from config
        channels[i].default_state = config->default_states[i]; // Set default state
        channels[i].fault_flag = 0;          // Initialize fault flag to 0
        channels[i].hard_fault_counter = 0;  // Initialize hard fault counter to 0
        channels[i].diagnose = config->dns[i];

        // Set initial state of channels.
        if  (channels[i].default_state == 0){
        	channel_off_impl(&channels[i]);
        }
        else{
        	channel_on_impl(&channels[i]);
                }
    }
}

#endif
