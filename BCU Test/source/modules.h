#ifndef _MODULES_H
#define _MODULES_H

#include "button.h"
#include "gpio_interface.h"

#define COUNTER_THRESHOLD 40

//================== GENERAL MODULE BLUEPRINT ========================
typedef struct moduleType {
    ChannelType* channel;
    buttonInput_t* button;
    uint8_t state;
    uint16_t counter;
    void (*init)(struct moduleType*);
    void (*activate)(struct moduleType*);
    void (*deactivate)(struct moduleType*);
} moduleType;

// Method to initialize any module
void initialize(moduleType* module, ChannelType* channel, buttonInput_t* button, uint8_t initialstate, uint16_t counter,
                void (*init_func)(moduleType*), void (*activate_func)(moduleType*), void (*deactivate_func)(moduleType*)) {
    module->channel = channel;
    module->button = button;
    module->state = initialstate;
    module->counter = counter;
    module->init = init_func;
    module->activate = activate_func;
    module->deactivate = deactivate_func;
}

// Method to initialize the module's channel based on the default state
void init(moduleType* self) {
    if (self->channel->default_state) {
        channel_on_impl(self->channel);
    } else {
        channel_off_impl(self->channel);
    }
}

// Method to activate a latch-type channel
void activate_latch(moduleType* self) {
    if (self->button->buttonState == BUTTON_RELEASED) {
        self->state = !self->state; // Toggle the state
    }
}

// Method to activate a momentary channel
void activate_moment(moduleType* self) {
    if ((self->button->buttonState == BUTTON_RELEASED) || (self->button->buttonState == BUTTON_HOLD)) {
        self->state = 1;
    } else {
        self->state = 0;
    }
}

// Method to activate a periodic toggle channel
void activate_toggle(moduleType* self) {
    if (self->counter >= COUNTER_THRESHOLD) {
        self->counter = 0;
        self->state = !self->state; // Toggle the state
    }
    self->counter++;

    if (self->state == 1) {
        channel_on_impl(self->channel);
    } else {
        channel_off_impl(self->channel);
    }
}

#endif
