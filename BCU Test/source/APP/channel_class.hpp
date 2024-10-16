#ifndef _CHANNEL_CLASS_H
#define _CHANNEL_CLASS_H

#include "board.h"
#include "MCAL/board_config.h"
#include "adc_driver.h"
#include "components.h"

#define FAULT_COUNTER_LIMIT 2

uint32_t global_adc;
uint8_t debug;

// Define the Channel class
class Channel {
private:
    pinconfigType* pins;  // Pointer to pinconfigType
    void channel_on_impl();
    void channel_off_impl();
    void latch_reset_impl();
    void diagnose_en_impl();
    float get_current();
    bool evaluate_fault();
   
public:
    bool state;
    bool fault_flag;
    uint8_t hard_fault_counter;
    uint16_t max_current;
    uint16_t inrush_current;
    uint16_t inrush_time;
    //current curve parameters
    float now_current;
    float rec_peak_current;
    uint32_t ch_on_tstamp;
    uint32_t ch_on_duration;
    uint32_t peak_I_tstamp;
    uint32_t peak_duration;

   // Default Constructor
    Channel() : pins(nullptr), fault_flag(false), hard_fault_counter(0) {}
 // Constructor to initialize Channel using a pointer to a pinconfigType object
    Channel(pinconfigType* config) 
        : pins(config), fault_flag(false), hard_fault_counter(0) {}
    
    uint8_t activate();
};

//private method definitions

    void Channel::channel_on_impl() {
            if (pins) {  // Check if pins is not null
                pal_lld_setpad(this->pins->gpio.port, this->pins->gpio.pin);
                this->ch_on_tstamp = osalThreadGetMicroseconds();
            }
        }

    void Channel:: channel_off_impl() {
        if (pins) {  // Check if pins is not null
            pal_lld_clearpad(this->pins->gpio.port, this->pins->gpio.pin);
        }
    }

    void Channel:: latch_reset_impl() {
        this->fault_flag = false;         // Reset fault flag
        this->hard_fault_counter = 0;     // Reset hard fault counter
    }

    void Channel:: diagnose_en_impl() {
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

    float Channel::get_current(void){
        diagnose_en_impl();
        osalThreadDelayMicroseconds(2);
        uint32_t adc_reading = adc_value[this->pins->adc_channel];
        global_adc = adc_reading;
        this->now_current = 0.00941917392531239*(float)adc_reading -0.016621870615556342;
        if(this->now_current>this->rec_peak_current){
            this->rec_peak_current = this->now_current;
            this->peak_I_tstamp = osalThreadGetMicroseconds();
            this->peak_duration = this->peak_I_tstamp - this->ch_on_tstamp;
        }
        adc_cb = 0;
        return this->now_current;
    }

    bool Channel::evaluate_fault(){
        
        this->now_current = this->get_current();
        this->ch_on_duration = osalThreadGetMicroseconds()-this->ch_on_tstamp;
        if(this->ch_on_duration<=this->inrush_time){
            if(this->now_current>= this->inrush_current){
            this->fault_flag = true;
            return this->fault_flag;
        }}
        else{
        if(this->now_current>= this->max_current){
            this->fault_flag = true;
            return this->fault_flag;
        }
        }
    }

// public method definitions
uint8_t Channel::activate(void){
    
   if(state){

        if(this->hard_fault_counter < FAULT_COUNTER_LIMIT){
            this->channel_on_impl();
            this->evaluate_fault();
        }
            while(this->fault_flag == true){
                this->hard_fault_counter++;
                this->channel_off_impl();
                this->channel_on_impl(); // resetting the hardware latch
                this->evaluate_fault();
                if(this->hard_fault_counter >= FAULT_COUNTER_LIMIT){
                     state = false;
                     this->fault_flag = false;
                     this->channel_off_impl();
                     debug = 20;
                     return 1; // error code 1 for hard fault event

                }
            }
   }
   else{
    this->channel_off_impl();
   }
}

void initialize_channels_from_config(pinconfigType* configs, Channel* channels) {
    for ( int i = 0; i < MAX_CHANNELS; ++i) {
        // Initialize each Channel with the corresponding pinconfigType
        channels[i] = Channel(&configs[i]);  // Use the parameterized constructor
    }
}

#endif
