

#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include "board.h"


#define MAX_CHANNELS 6


typedef struct{
	uint8_t pins[MAX_CHANNELS];
	uint8_t ports[MAX_CHANNELS];
	uint8_t default_states[MAX_CHANNELS];
}pinconfigType;

pinconfigType pinconfig = {
    .pins = {HS_P1, HS_P2, HS_P3, HS_P4, HS_P5, HS_P6},
    .ports = {PORT_HS_P1, PORT_HS_P2, PORT_HS_P3, PORT_HS_P4, PORT_HS_P5, PORT_HS_P6},
    .default_states = {0, 0, 0, 0, 0, 0}  // Example values

};

#endif
