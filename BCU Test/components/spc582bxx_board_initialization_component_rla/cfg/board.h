/****************************************************************************
*
* Copyright © 2017-2022 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

#ifndef _BOARD_H_
#define _BOARD_H_

#include "pal.h"

/*
 * Setup for a generic SPC582Bxx board.
 */

/*
 * Board identifiers.
 */
#define BOARD_GENERIC_SPC582BXX
#define BOARD_NAME                  "Generic SPC582Bxx"

/*
 * Support macros.
 */
#define MSCR_IO_INDEX(port, pin)    (((port) * 16U) + (pin))

/*
 * I/O definitions.
 */
#define PIN_TX_4_1                  10U
#define PIN_RX_4_1                  11U
#define LS_P7                       10U
#define LS_CS                       11U
#define LS_IDLE                     8U
#define LS_P8                       9U
#define HS_P4                       12U
#define LED2                        13U
#define LED1                        14U
#define DEN_6                       15U
#define DSEL_1_2                    3U
#define HS_P2                       4U
#define PIN_SIN_0                   11U
#define DEN_1_2                     12U
#define HS_P1                       13U
#define DEN_3_4                     14U
#define HS_P3                       15U
#define IN1                         10U
#define IN2                         11U
#define ADC_1_2                     2U
#define ADC_5                       3U
#define DSEL_3_4                    3U
#define PIN_SCK_0                   11U
#define PIN_SOUT_0                  12U
#define HS_P6                       4U
#define DEN_5                       1U
#define HS_P5                       2U
#define ADC_6                       3U
#define ADC_3_4                     6U

/*
 * PORT definitions.
 */
#define PORT_PIN_TX_4_1             PORT_A
#define PORT_PIN_RX_4_1             PORT_A
#define PORT_LS_P7                  PORT_B
#define PORT_LS_CS                  PORT_B
#define PORT_LS_IDLE                PORT_B
#define PORT_LS_P8                  PORT_B
#define PORT_HS_P4                  PORT_C
#define PORT_LED2                   PORT_C
#define PORT_LED1                   PORT_C
#define PORT_DEN_6                  PORT_C
#define PORT_DSEL_1_2               PORT_C
#define PORT_HS_P2                  PORT_C
#define PORT_PIN_SIN_0              PORT_D
#define PORT_DEN_1_2                PORT_D
#define PORT_HS_P1                  PORT_D
#define PORT_DEN_3_4                PORT_D
#define PORT_HS_P3                  PORT_D
#define PORT_IN1                    PORT_E
#define PORT_IN2                    PORT_E
#define PORT_ADC_1_2                PORT_E
#define PORT_ADC_5                  PORT_E
#define PORT_DSEL_3_4               PORT_F
#define PORT_PIN_SCK_0              PORT_G
#define PORT_PIN_SOUT_0             PORT_G
#define PORT_HS_P6                  PORT_H
#define PORT_DEN_5                  PORT_I
#define PORT_HS_P5                  PORT_I
#define PORT_ADC_6                  PORT_I
#define PORT_ADC_3_4                PORT_I

/*
 * MSCR_IO definitions.
 */
#define MSCR_IO_PIN_TX_4_1          MSCR_IO_INDEX(PORT_PIN_TX_4_1, PIN_TX_4_1)
#define MSCR_IO_PIN_RX_4_1          MSCR_IO_INDEX(PORT_PIN_RX_4_1, PIN_RX_4_1)
#define MSCR_IO_LS_P7               MSCR_IO_INDEX(PORT_LS_P7, LS_P7)
#define MSCR_IO_LS_CS               MSCR_IO_INDEX(PORT_LS_CS, LS_CS)
#define MSCR_IO_LS_IDLE             MSCR_IO_INDEX(PORT_LS_IDLE, LS_IDLE)
#define MSCR_IO_LS_P8               MSCR_IO_INDEX(PORT_LS_P8, LS_P8)
#define MSCR_IO_HS_P4               MSCR_IO_INDEX(PORT_HS_P4, HS_P4)
#define MSCR_IO_LED2                MSCR_IO_INDEX(PORT_LED2, LED2)
#define MSCR_IO_LED1                MSCR_IO_INDEX(PORT_LED1, LED1)
#define MSCR_IO_DEN_6               MSCR_IO_INDEX(PORT_DEN_6, DEN_6)
#define MSCR_IO_DSEL_1_2            MSCR_IO_INDEX(PORT_DSEL_1_2, DSEL_1_2)
#define MSCR_IO_HS_P2               MSCR_IO_INDEX(PORT_HS_P2, HS_P2)
#define MSCR_IO_PIN_SIN_0           MSCR_IO_INDEX(PORT_PIN_SIN_0, PIN_SIN_0)
#define MSCR_IO_DEN_1_2             MSCR_IO_INDEX(PORT_DEN_1_2, DEN_1_2)
#define MSCR_IO_HS_P1               MSCR_IO_INDEX(PORT_HS_P1, HS_P1)
#define MSCR_IO_DEN_3_4             MSCR_IO_INDEX(PORT_DEN_3_4, DEN_3_4)
#define MSCR_IO_HS_P3               MSCR_IO_INDEX(PORT_HS_P3, HS_P3)
#define MSCR_IO_IN1                 MSCR_IO_INDEX(PORT_IN1, IN1)
#define MSCR_IO_IN2                 MSCR_IO_INDEX(PORT_IN2, IN2)
#define MSCR_IO_ADC_1_2             MSCR_IO_INDEX(PORT_ADC_1_2, ADC_1_2)
#define MSCR_IO_ADC_5               MSCR_IO_INDEX(PORT_ADC_5, ADC_5)
#define MSCR_IO_DSEL_3_4            MSCR_IO_INDEX(PORT_DSEL_3_4, DSEL_3_4)
#define MSCR_IO_PIN_SCK_0           MSCR_IO_INDEX(PORT_PIN_SCK_0, PIN_SCK_0)
#define MSCR_IO_PIN_SOUT_0          MSCR_IO_INDEX(PORT_PIN_SOUT_0, PIN_SOUT_0)
#define MSCR_IO_HS_P6               MSCR_IO_INDEX(PORT_HS_P6, HS_P6)
#define MSCR_IO_DEN_5               MSCR_IO_INDEX(PORT_DEN_5, DEN_5)
#define MSCR_IO_HS_P5               MSCR_IO_INDEX(PORT_HS_P5, HS_P5)
#define MSCR_IO_ADC_6               MSCR_IO_INDEX(PORT_ADC_6, ADC_6)
#define MSCR_IO_ADC_3_4             MSCR_IO_INDEX(PORT_ADC_3_4, ADC_3_4)

/*
 * MSCR_MUX definitions.
 */
#define MSCR_MUX_PIN_RX_4_1         252U
#define MSCR_MUX_PIN_SIN_0          368U

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
