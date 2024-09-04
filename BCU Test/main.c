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

	for (;;) {
		//setOutputs();
		osalThreadDelayMilliseconds(10);
	}
}
