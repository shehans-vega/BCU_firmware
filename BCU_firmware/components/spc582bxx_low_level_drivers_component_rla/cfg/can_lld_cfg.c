/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    can_lld_cfg.c
 * @brief   CAN Driver configuration code.
 *
 * @addtogroup CAN
 * @{
 */
 
#include "can_lld_cfg.h"

#if (LLD_USE_CAN == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   Structure defining the CAN configuration "mcanconf".
 */
CANConfig can_config_mcanconf = {
  /* loopback */
  CAN_NO_LOOPBACK,
  /* endianness */
  CAN_BIG_ENDIAN,
  /* sync jump width */ 
  1U,  
  /* time segment before sample point */
  2U,
  /* time segment after sample point */
  3U,
  /* clock prescaler */
  2U,
  
  /* Canfd configuration */
  FALSE,
  /* canfd bit rate switch */
  FALSE,
   /* sync jump width */ 
  1U,  
  /* time segment before sample point */
  1U,
  /* time segment after sample point */
  0U,
  /* clock prescaler */
  1U,
  /* transceiver delay compensation enabled */
  FALSE,
  /* transmitter delay compensation value */
  0U,
  /* transmitter delay compensation offset */
  0U,
  /* transmitter delay compensation filter window length */
  0U,

  /*can rx interrupt line*/
  CAN_LINE0_INT,
  /*can rx interrupt call back */
   mcanconf_rxcb,
  /* FIFO 0 is not used */
  CAN_FIFO0_INT_DISABLE,0,NULL,0,NULL,0,NULL,0,NULL,
  /* FIFO 1 is not used */
  CAN_FIFO1_INT_DISABLE,0,NULL,0,NULL,0,NULL,0,NULL,
  /* rx standard buffer filters */
  {
  {0x27UL,50UL,0U,7U}, /* standard filter 0*/
  {0UL,0UL,0U,0U},  /* standard_filter unused 0 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* standard_filter unused 1 (MISRA Compliance) */
  },
    /* rx extended buffer filters */
  {
  {0UL,0UL,0U,0U},  /* extended_filter unused 0 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* extended_filter unused 1 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* extended_filter unused 2 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* extended_filter unused 3 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* extended_filter unused 4 (MISRA Compliance) */
  },
/* number of standard filters */
  1U,
/* number of extended filters */
  0U,
  /* number of Rx Buffers */
  51U,
/* number of FIFO 0 Buffers */
  0U,
/* number of FIFO 1 Buffers */
  0U,
/* Transmission Mode */
  CAN_DEDICATED_TXBUFFER,
/* number of Tx Buffers */
  16U,
/* number of FIFO or QUEUE Tx Buffers */
  8U,
/* Error Callback*/
  NULL,
};

/**
 * @brief   Structure defining the CAN configuration "mcanconf_ext".
 */
CANConfig can_config_mcanconf_ext = {
  /* loopback */
  CAN_NO_LOOPBACK,
  /* endianness */
  CAN_BIG_ENDIAN,
  /* sync jump width */ 
  1U,  
  /* time segment before sample point */
  2U,
  /* time segment after sample point */
  3U,
  /* clock prescaler */
  4U,
  
  /* Canfd configuration */
  FALSE,
  /* canfd bit rate switch */
  FALSE,
   /* sync jump width */ 
  1U,  
  /* time segment before sample point */
  1U,
  /* time segment after sample point */
  0U,
  /* clock prescaler */
  1U,
  /* transceiver delay compensation enabled */
  FALSE,
  /* transmitter delay compensation value */
  0U,
  /* transmitter delay compensation offset */
  0U,
  /* transmitter delay compensation filter window length */
  0U,

  /*can rx interrupt line*/
  CAN_LINE0_INT,
  /*can rx interrupt call back */
   mcanconf_ext_rxcb,
  /* FIFO 0 is not used */
  CAN_FIFO0_INT_DISABLE,0,NULL,0,NULL,0,NULL,0,NULL,
  /* FIFO 1 is not used */
  CAN_FIFO1_INT_DISABLE,0,NULL,0,NULL,0,NULL,0,NULL,
  /* rx standard buffer filters */
  {
  {0x32UL,50UL,0U,7U}, /* standard filter 0*/
  {0UL,0UL,0U,0U},  /* standard_filter unused 0 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* standard_filter unused 1 (MISRA Compliance) */
  },
    /* rx extended buffer filters */
  {
  {0xcf00121UL,50UL,0U,7U}, /* Extended filter 0*/
  {0x10f8109aUL,50UL,0U,7U}, /* Extended filter 1*/
  {0x10f8108dUL,50UL,0U,7U}, /* Extended filter 2*/
  {0UL,0UL,0U,0U},  /* extended_filter unused 0 (MISRA Compliance) */
  {0UL,0UL,0U,0U},  /* extended_filter unused 1 (MISRA Compliance) */
  },
/* number of standard filters */
  1U,
/* number of extended filters */
  3U,
  /* number of Rx Buffers */
  51U,
/* number of FIFO 0 Buffers */
  0U,
/* number of FIFO 1 Buffers */
  0U,
/* Transmission Mode */
  CAN_DEDICATED_TXBUFFER,
/* number of Tx Buffers */
  16U,
/* number of FIFO or QUEUE Tx Buffers */
  8U,
/* Error Callback*/
  NULL,
};

/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

#endif /* LLD_USE_CAN */

/** @} */
