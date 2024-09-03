/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Yohan Harshamal, Vega Innovations, Sri Lanka
 */

#include "source/main.h"

int main(void) {
	componentsInit();
	irqIsrEnable();

	for (;;) {
		setOutputs();
		osalThreadDelayMilliseconds(10);
	}
}
