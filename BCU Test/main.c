/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: sheh
 */

#include "source/main.h"

int main(void) {
	componentsInit();
	irqIsrEnable();
	ADC_init();
	CAN_init();
	
	ChannelType channels[MAX_CHANNELS];
	init_channels_from_config(channels, &pinconfig);

	for (;;) {
		CAN_send();
		osalThreadDelayMilliseconds(10);
	}
}
