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

	for (;;) {
		CAN_send();
		osalThreadDelayMilliseconds(10);
	}
}
