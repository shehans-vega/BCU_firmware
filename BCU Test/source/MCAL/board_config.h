

#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "board.h"

#ifdef __cplusplus
 }
#endif

#define MAX_CHANNELS 6

typedef struct {
    uint8_t pin;
    uint8_t port;
} gpioType;

typedef struct {
    gpioType gpio;
    gpioType dns_pins;
    gpioType dsel_pins;
    uint8_t den;
    uint8_t dsel;
    uint8_t adc_channel;
    bool default_state;
} pinconfigType;

gpioType onboardLED[2] = {
		{.pin = LED1, .port = PORT_LED1},
		{.pin = LED2, .port = PORT_LED2}

};

// Create and initialize the array of pinconfigType
pinconfigType pinconfig[6] = {
    { .gpio = { .pin = HS_P1, .port = PORT_HS_P1 }, .dns_pins = { .pin = DEN_1_2, .port = PORT_DEN_1_2 }, .dsel_pins = { .pin = DSEL_1_2, .port = PORT_DSEL_1_2 }, .den = 1, .dsel = 0, .adc_channel = 1, .default_state = false },
    { .gpio = { .pin = HS_P2, .port = PORT_HS_P2 }, .dns_pins = { .pin = DEN_1_2, .port = PORT_DEN_1_2 }, .dsel_pins = { .pin = DSEL_1_2, .port = PORT_DSEL_1_2 }, .den = 1, .dsel = 1, .adc_channel = 0, .default_state = false },
    { .gpio = { .pin = HS_P3, .port = PORT_HS_P3 }, .dns_pins = { .pin = DEN_3_4, .port = PORT_DEN_3_4 }, .dsel_pins = { .pin = DSEL_1_2, .port = PORT_DSEL_3_4 }, .den = 1, .dsel = 0, .adc_channel = 1, .default_state = false },
    { .gpio = { .pin = HS_P4, .port = PORT_HS_P4 }, .dns_pins = { .pin = DEN_3_4, .port = PORT_DEN_3_4 }, .dsel_pins = { .pin = DSEL_1_2, .port = PORT_DSEL_3_4 }, .den = 1, .dsel = 1, .adc_channel = 0, .default_state = false },
    { .gpio = { .pin = HS_P5, .port = PORT_HS_P5 }, .dns_pins = { .pin = DEN_5, .port = PORT_DEN_5 }, .dsel_pins = { 0, 0 }, .den = 1, .dsel = 0, .adc_channel = 2, .default_state = false },
    { .gpio = { .pin = HS_P6, .port = PORT_HS_P6 }, .dns_pins = { .pin = DEN_6, .port = PORT_DEN_6 }, .dsel_pins = { 0, 0 }, .den = 1, .dsel = 0, .adc_channel = 3, .default_state = false }
};

#endif
