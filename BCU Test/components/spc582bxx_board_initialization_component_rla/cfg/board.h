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
#define OUT6                        12U
#define OUT4                        4U
#define OUT3                        13U
#define OUT5                        15U
#define OUT1                        4U
#define OUT2                        2U

/*
 * PORT definitions.
 */
#define PORT_PIN_TX_4_1             PORT_A
#define PORT_PIN_RX_4_1             PORT_A
#define PORT_OUT6                   PORT_C
#define PORT_OUT4                   PORT_C
#define PORT_OUT3                   PORT_D
#define PORT_OUT5                   PORT_D
#define PORT_OUT1                   PORT_H
#define PORT_OUT2                   PORT_I

/*
 * MSCR_IO definitions.
 */
#define MSCR_IO_PIN_TX_4_1          MSCR_IO_INDEX(PORT_PIN_TX_4_1, PIN_TX_4_1)
#define MSCR_IO_PIN_RX_4_1          MSCR_IO_INDEX(PORT_PIN_RX_4_1, PIN_RX_4_1)
#define MSCR_IO_OUT6                MSCR_IO_INDEX(PORT_OUT6, OUT6)
#define MSCR_IO_OUT4                MSCR_IO_INDEX(PORT_OUT4, OUT4)
#define MSCR_IO_OUT3                MSCR_IO_INDEX(PORT_OUT3, OUT3)
#define MSCR_IO_OUT5                MSCR_IO_INDEX(PORT_OUT5, OUT5)
#define MSCR_IO_OUT1                MSCR_IO_INDEX(PORT_OUT1, OUT1)
#define MSCR_IO_OUT2                MSCR_IO_INDEX(PORT_OUT2, OUT2)

/*
 * MSCR_MUX definitions.
 */
#define MSCR_MUX_PIN_RX_4_1         252U

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
