

#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include "board.h"

#define MAX_CHANNELS 6

typedef struct {
    uint8_t pin;
    uint8_t port;
} gpioType;

typedef struct {
    gpioType dns_pins;
    gpioType dsel_pins;
    uint8_t den;
    uint8_t dsel;
    uint8_t adc_channel;
} diagnoseType;

typedef struct {
    gpioType gpio[MAX_CHANNELS];
    uint8_t default_states[MAX_CHANNELS];
    diagnoseType dns[MAX_CHANNELS];
} pinconfigType;

gpioType onboardLED[2] = {
		{.pin = LED1, .port = PORT_LED1},
		{.pin = LED2, .port = PORT_LED2}

};

 pinconfigType pinconfig = {
    .gpio = {
        {.pin = HS_P1, .port = PORT_HS_P1},
        {.pin = HS_P2, .port = PORT_HS_P2},
        {.pin = HS_P3, .port = PORT_HS_P3},
        {.pin = HS_P4, .port = PORT_HS_P4},
        {.pin = HS_P5, .port = PORT_HS_P5},
        {.pin = HS_P6, .port = PORT_HS_P6}
    },
    .default_states = {0, 0, 0, 0, 0, 0},
    .dns = {
        {
            .dns_pins = {DEN_1_2, PORT_DEN_1_2},
			.dsel_pins ={DSEL_1_2, PORT_DSEL_1_2},
            .den =  1,
			.dsel = 0,
            .adc_channel = 49U
        },
        {
            .dns_pins = {DEN_1_2, PORT_DEN_1_2},
			.dsel_pins ={DSEL_1_2, PORT_DSEL_1_2},
			.den =  1,
			.dsel = 1,
            .adc_channel = 49U
        },
        {
            .dns_pins = {DEN_3_4, PORT_DEN_3_4},
			.dsel_pins ={DSEL_1_2, PORT_DSEL_3_4},
			.den =  1,
			.dsel = 0,
            .adc_channel = 13U
        },
        {
            .dns_pins = {DEN_3_4, PORT_DEN_3_4},
			.dsel_pins = {DSEL_1_2, PORT_DSEL_3_4},
			.den =  1,
			.dsel = 1,
            .adc_channel = 13U
        },
        {
            .dns_pins = {DEN_5, PORT_DEN_5},
			.dsel_pins = {0, 0},
			.den = 1,
			.dsel = 0,
            .adc_channel = 17U
        },
        {
            .dns_pins = {DEN_6, PORT_DEN_6},
			.dsel_pins = {0, 0},
            .den = 1,
			.dsel = 0,
            .adc_channel = 39U
        }
    }
};

#endif
