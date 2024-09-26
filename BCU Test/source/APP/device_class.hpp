#ifndef _DEVICE_MAKER_H
#define _DEVICE_MAKER_H

#include "gpio_interface.hpp"
#include "input_elements.h"
#include "output_elements.h"

#define highbeam_current 1
#define lowbeam_current 1
#define COUNTER_THRESHOLD 40

class Device
{
    
private:
public:
    Channel *device_channel;
    buttonInput_t *device_button;
    uint8_t max_current;
    uint8_t counter;
    bool state;

    Device();
    Device(Channel *channel, buttonInput_t *button, uint8_t current) : device_channel(channel), device_button(button), max_current(current)
    {
        state = 1;
    };
    virtual void activate() = 0;
    virtual bool evaluate_press() = 0;
    virtual void control_signal() = 0; // the master module will call this function
    bool fault;
};

class momentary_Device : public Device
{
public:
    momentary_Device(Channel *channel, buttonInput_t *button, uint8_t current) : Device(channel, button, current)
    {
        state = 0;
        counter = 0;
    }
    bool evaluate_press() override
    {
        if ((this->device_button->buttonState == BUTTON_PRESSED) || (this->device_button->buttonState == BUTTON_HOLD))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal() override
    {
        if (this->evaluate_press())
        {
            this->state = 1;
        }
        else
        {
            this->state = 0;
        }
    }

    void activate() override
    {

        if (this->state == 1)
        {
            this->device_channel->channel_on_impl();
        }
        else
        {
            this->device_channel->channel_off_impl();
        }
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
        if ((this->device_button->buttonState == BUTTON_RELEASED) && (this->device_button->buttonPrevState == (BUTTON_PRESSED || BUTTON_HOLD)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal() override {
         this->state = !this->state;
    }

    void activate() override
    {

        if (this->state == 1)
        {
            this->device_channel->channel_on_impl();
        }
        else
        {
            this->device_channel->channel_off_impl();
        }
    }
};

class toggle_Device : public Device
{
public:
    toggle_Device(Channel *channel, buttonInput_t *button, uint8_t current) : Device(channel, button, current)
    {
        state = 0;
        counter = 0;
    }

    bool evaluate_press() override
    {
        if ((this->device_button->buttonState == BUTTON_RELEASED) && (this->device_button->buttonPrevState == (BUTTON_PRESSED || BUTTON_HOLD)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void control_signal() override {
         this->state = !this->state;
    }

    void activate() override
    {
        static bool pulse = false;

        if (state)
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
            this->device_channel->channel_on_impl();
        }
        else
        {
            this->device_channel->channel_off_impl();
        }
    }
};

#endif
