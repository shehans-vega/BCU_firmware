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

#include "board.h"
#include "clock.h"

/*
 * Initial setup of MSCR_IO registers, the list is terminated
 * by a {-1, 0, 0}.
 */
static spc_mscr_io_init_t spc_mscr_io_init[] = {
  {(int16_t)MSCR_IO_PIN_TX_4_1, (iomode_t)(PAL_SPC5_SSS(1) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_PIN_RX_4_1, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(0) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE | PAL_SPC5_WPUE), PAL_LOW},
  {(int16_t)MSCR_IO_LS_P7, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_LS_CS, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_LS_IDLE, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_LS_P8, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P4, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_LED2, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_LED1, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_DEN_6, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_DSEL_1_2, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P2, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_PIN_SIN_0, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(0) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE | PAL_SPC5_WPUE), PAL_LOW},
  {(int16_t)MSCR_IO_DEN_1_2, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P1, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_DEN_3_4, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P3, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_IN1, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_IN2, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_DSEL_3_4, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_PIN_SCK_0, (iomode_t)(PAL_SPC5_SSS(1) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_PIN_SOUT_0, (iomode_t)(PAL_SPC5_SSS(1) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P6, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_DEN_5, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {(int16_t)MSCR_IO_HS_P5, (iomode_t)(PAL_SPC5_SSS(0) | PAL_SPC5_OERC(0) | PAL_SPC5_ODC(2) | PAL_SPC5_SMC | PAL_SPC5_ILS(0) | PAL_SPC5_IBE), PAL_LOW},
  {-1, 0, 0}
};

/*
 * Initial setup of MSCR_MUX registers, the list is terminated
 * by a {-1, 0}.
 */
static spc_mscr_mux_init_t spc_mscr_mux_init[] = {
  {(int16_t)(MSCR_MUX_PIN_RX_4_1), 1U},
  {(int16_t)(MSCR_MUX_PIN_SIN_0), 2U},
  {-1, 0}
};

/**
 * @brief   PAL setup.
 */
static PALConfig pal_default_config = {
  spc_mscr_io_init,
  spc_mscr_mux_init
};

/*
 * Board-specific initialization code.
 */
void boardInit(void) {

  pal_init(&pal_default_config);
}
