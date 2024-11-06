#ifndef _DEVICE_MAKER_H
#define _DEVICE_MAKER_H

#include "channel_class.hpp"
#include "input_elements.h"
#include "output_elements.h"
#include "timer.h"

#define TOGGLE_INTERVAL 600

uint8_t temp = 0; // delete this
bool debug_delay;

class Device
{
    
private:
public:
    Channel *device_channel;
    buttonInput_t *device_button;
    uint16_t device_max_current;
    uint16_t device_inrush_current;
    uint16_t device_inrush_time; // microseconds
    uint16_t counter;
    bool state;

    Device();
    Device(Channel *channel, buttonInput_t *button, uint16_t current,uint16_t inrush_current,uint16_t inrush_time) : device_channel(channel), device_button(button), device_max_current(current),device_inrush_current(inrush_current),device_inrush_time(inrush_time)
    {
        this->device_channel->max_current = device_max_current;
        this->device_channel->inrush_current = device_inrush_current;
        this->device_channel->inrush_time = device_inrush_time;
        state = 0;
    };
    virtual void activate() = 0;
    virtual bool evaluate_press() = 0;
    virtual void control_signal(bool x ) = 0; // the master module will call this function
    bool fault;
};

//=======================Derived Classes======================
class momentary_Device : public Device
{
public:
    momentary_Device(Channel *channel, buttonInput_t *button, uint16_t current,uint16_t inrush_current,uint16_t inrush_time ) : Device(channel, button, current,inrush_current,inrush_time)
    {
        state = 0;
        counter = 0;
    }
    bool evaluate_press() override
    {   button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_PRESSED) || (this->device_button->buttonState == BUTTON_HOLD))
        {    
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal(bool control) override
    {
       this->state = control;
    }

    void activate() override
    {

        if (this->state == 1)
        {
            this->device_channel->state = true;
         }  
        else
        {
            this->device_channel->state = false;
        }
        this->device_channel->activate();
    }
};

class latch_Device : public Device
{
public:
    latch_Device(Channel *channel, buttonInput_t *button, uint16_t current,uint16_t inrush_current,uint16_t inrush_time ) : Device(channel, button, current,inrush_current,inrush_time)
    {
        state = 0;
        counter = 0;
    }
    bool evaluate_press() override
    {   
        button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_PRESSED) || (this->device_button->buttonState == BUTTON_HOLD))
        {   
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal(bool control) override {
           this->state = control;
    }

    void activate() override
    {

        if (this->state == 1)
        {
            this->device_channel->state = true;
        }
        else
        {
            this->device_channel->state = false;
        }
        this->device_channel->activate();
    }
};

class toggle_Device : public Device
{
public:
    unsigned long previousMillis = 0;
    bool pulse = false;
    toggle_Device(Channel *channel, buttonInput_t *button, uint16_t current,uint16_t inrush_current,uint16_t inrush_time ) : Device(channel, button, current,inrush_current,inrush_time)
    {
        this->state = 0;
        this->counter = 0;
    }

    bool evaluate_press() override
    {   button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_PRESSED) || (this->device_button->buttonState == BUTTON_HOLD))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal(bool control) override {
         this->state = control;
    }

    void activate() override
    {
        
        if (this->state)
        {    temp++;
            debug_delay = pseudo_delay(TOGGLE_INTERVAL,previousMillis);
            if (debug_delay)
            {
                pulse = !pulse; // Toggle the state
            }
            
        }
        else
        {
           pulse = 0;
        }

        if (pulse == true)
        {
            this->device_channel->state = true;
        }
        else
        {
            this->device_channel->state = false;
        }
        this->device_channel->activate();
    }
};

#endif
