/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: shehan
 */

#include "source/main.h"

int main(void) {
	componentsInit();
	irqIsrEnable();
	ADC_init();
	CAN_init();
	//Initialize all the channels to hschannels array
	init_channels_from_config(hschannels, &pinconfig);
	initialize_modules();

	//initialize_modules();

	for (;;) {
		CAN_send();
//		channel_on_impl(&hschannels[2]);
		activate_modules();
		osalThreadDelayMilliseconds(10);
	}
}
