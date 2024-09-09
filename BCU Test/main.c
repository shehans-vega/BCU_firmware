/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: sheh
 */

#include "source/main.h"

ChannelType hschannels[MAX_CHANNELS];

int main(void) {
	componentsInit();
	irqIsrEnable();
	ADC_init();
	CAN_init();
	
	init_channels_from_config(hschannels, &pinconfig);
	channel_on_impl(&hschannels[2]);
	diagnose_en_impl(&hschannels[2]);
	for (;;) {
		CAN_send();
		osalThreadDelayMilliseconds(10);
	}
}
