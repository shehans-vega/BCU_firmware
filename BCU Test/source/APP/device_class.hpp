#ifndef _DEVICE_MAKER_H
#define _DEVICE_MAKER_H

#include "channel_class.hpp"
#include "input_elements.h"
#include "output_elements.h"

#define highbeam_current 1
#define lowbeam_current 1
#define COUNTER_THRESHOLD 500

uint8_t temp = 0;

class Device
{
    
private:
public:
    Channel *device_channel;
    buttonInput_t *device_button;
    uint16_t device_max_current;
    uint16_t counter;
    bool state;

    Device();
    Device(Channel *channel, buttonInput_t *button, uint8_t current) : device_channel(channel), device_button(button), device_max_current(current)
    {
        this->device_channel->max_current = device_max_current;
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
    momentary_Device(Channel *channel, buttonInput_t *button, uint8_t current) : Device(channel, button, current)
    {
        state = 0;
        counter = 0;
    }
    bool evaluate_press() override
    {   button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_PRESSED) || (this->device_button->buttonState == BUTTON_HOLD))
        {   temp++ ;
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
    latch_Device(Channel *channel, buttonInput_t *button, uint8_t current) : Device(channel, button, current)
    {
        state = 0;
        counter = 0;
    }
    bool evaluate_press() override
    {   
        button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_RELEASED) && ((this->device_button->buttonPrevState ==  BUTTON_HOLD)||(this->device_button->buttonPrevState ==  BUTTON_PRESSED)))
        {   
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal(bool control) override {
        if(control){
         this->state = !this->state;}
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
    bool pulse = false;
    toggle_Device(Channel *channel, buttonInput_t *button, uint8_t current) : Device(channel, button, current)
    {
        this->state = 0;
        this->counter = 0;
    }

    bool evaluate_press() override
    {   button_state(this->device_button);
        if ((this->device_button->buttonState == BUTTON_RELEASED) && ((this->device_button->buttonPrevState ==  BUTTON_HOLD)||(this->device_button->buttonPrevState ==  BUTTON_PRESSED)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal(bool control) override {
        if(control){
         this->state = !this->state;}
    }

    void activate() override
    {
        
        if (this->state)
        {
            if (this->counter >= COUNTER_THRESHOLD)
            {
                this->counter = 0;
                pulse = !pulse; // Toggle the state
            }
            this->counter++;
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
