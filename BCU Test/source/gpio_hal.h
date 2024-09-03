/*
 * gpio_hal.h
 *
 *  Created on: Aug 22, 2024
 *      Author: User
 */

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_

uint8_t Channel1 = 0;
uint8_t Channel2 = 0;
uint8_t Channel3 = 0;
uint8_t Channel4 = 0;
uint8_t Channel5 = 0;
uint8_t Channel6 = 0;

#define CH1_ON		pal_lld_setpad(PORT_H, OUT1)
#define CH1_OFF		pal_lld_clearpad(PORT_H, OUT1)
#define CH2_ON		pal_lld_setpad(PORT_I, OUT2)
#define CH2_OFF		pal_lld_clearpad(PORT_I, OUT2)
#define CH3_ON		pal_lld_setpad(PORT_D, OUT3)
#define CH3_OFF		pal_lld_clearpad(PORT_D, OUT3)
#define CH4_ON		pal_lld_setpad(PORT_C, OUT4)
#define CH4_OFF		pal_lld_clearpad(PORT_C, OUT4)
#define CH5_ON		pal_lld_setpad(PORT_D, OUT5)
#define CH5_OFF		pal_lld_clearpad(PORT_D, OUT5)
#define CH6_ON		pal_lld_setpad(PORT_C, OUT6)
#define CH6_OFF		pal_lld_clearpad(PORT_C, OUT6)

void setOutputs(void) {
	if (Channel1) {
		CH1_ON;
	} else {
		CH1_OFF;
	}

	if (Channel2) {
		CH2_ON;
	} else {
		CH2_OFF;
	}

	if (Channel3) {
		CH3_ON;
	} else {
		CH3_OFF;
	}

	if (Channel4) {
		CH4_ON;
	} else {
		CH4_OFF;
	}
	if (Channel5) {
		CH5_ON;
	} else {
		CH5_OFF;
	}

	if (Channel6) {
		CH6_ON;
	} else {
		CH6_OFF;
	}
}
#endif /* GPIO_HAL_H_ */
