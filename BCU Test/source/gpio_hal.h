/*
 * gpio_hal.h
 *
 *  Created on: Aug 22, 2024
 *      Author: User
 */

#include "board.h"

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_


#define CH1_ON		pal_lld_setpad(PORT_HS_P1, HS_P1)
#define CH1_OFF		pal_lld_clearpad(PORT_HS_P1, HS_P1)
#define CH2_ON		pal_lld_setpad(PORT_HS_P2, HS_P2)
#define CH2_OFF		pal_lld_clearpad(PORT_HS_P2, HS_P2)
#define CH3_ON		pal_lld_setpad(PORT_HS_P3, HS_P3)
#define CH3_OFF		pal_lld_clearpad(PORT_HS_P3, HS_P3)
#define CH4_ON		pal_lld_setpad(PORT_HS_P4, HS_P4)
#define CH4_OFF		pal_lld_clearpad(PORT_HS_P4, HS_P4)
#define CH5_ON		pal_lld_setpad(PORT_HS_P5, HS_P5)
#define CH5_OFF		pal_lld_clearpad(PORT_HS_P5, HS_P5)
#define CH6_ON		pal_lld_setpad(PORT_HS_P6, HS_P6)
#define CH6_OFF		pal_lld_clearpad(PORT_HS_P6, HS_P6)

#define DEN_1_2_ON		pal_lld_setpad(PORT_DEN_1_2, DEN_1_2)
#define SEL_CH1			pal_lld_setpad(PORT_DSEL_1_2, DSEL_1_2)
#define SEL_CH2			pal_lld_clearpad(PORT_DSEL_1_2, DSEL_1_2)
#define DEN_3_4_ON		pal_lld_setpad(PORT_DEN_3_4, DEN_3_4)
#define SEL_CH3			pal_lld_setpad(PORT_HS_P3, HS_P3)
#define SEL_CH4			pal_lld_clearpad(PORT_HS_P1, HS_P1)
#define DEN_5_ON		pal_lld_setpad(PORT_DEN_5, DEN_5)
#define DEN_6_ON		pal_lld_setpad(PORT_DEN_6, DEN_6)

uint16_t IS_1_2;
uint16_t IS_3_4;
uint16_t IS_5;
uint16_t IS_6;





#endif /* GPIO_HAL_H_ */
