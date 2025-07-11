/****************************************************************************
*
* Copyright (c) 2015-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    lldconf.h
 * @brief   LLD configuration header.
 * @details LLD configuration file, this file allows to enable or disable the
 *          various device drivers from your application. You may also use
 *          this file in order to override the device drivers default settings.
 *
 * @addtogroup LLD_CONF
 * @{
 */

#ifndef _LLDCONF_H_
#define _LLDCONF_H_

/**
 * @name    Drivers enable switches
 */
#define LLD_USE_DMA                 TRUE
#define LLD_USE_PAL                 TRUE
#define LLD_USE_PIT                 FALSE
#define LLD_USE_STM                 FALSE
#define LLD_USE_SERIAL              FALSE
#define LLD_USE_PWM                 FALSE
#define LLD_USE_ICU                 FALSE
#define LLD_USE_CAN                 TRUE
#define LLD_USE_SPI                 FALSE
#define LLD_USE_ADC                 FALSE
#define LLD_USE_CTU                 FALSE
#define LLD_USE_I2C                 FALSE
#define LLD_USE_RTC                 FALSE
#define LLD_USE_SWT                 FALSE
#define LLD_USE_SARADC              TRUE
#define LLD_USE_FCCU                FALSE
#define LLD_USE_CRC                 FALSE
#define LLD_USE_WKPU                FALSE
#define LLD_USE_LIN                 FALSE
#define LLD_USE_I2S                 FALSE
#define LLD_USE_BCTU                FALSE
#define LLD_USE_AIC                 FALSE
/** @} */

/*===========================================================================*/
/**
 * @name SPI driver related setting
 * @{
 */
/*===========================================================================*/

/**
 * @brief   Enables synchronous APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if !defined(SPI_USE_WAIT) || defined(__DOXYGEN__)
#define SPI_USE_WAIT                TRUE
#endif

/**
 * @brief   Enables the @p spiAcquireBus() and @p spiReleaseBus() APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if !defined(SPI_USE_MUTUAL_EXCLUSION) || defined(__DOXYGEN__)
#define SPI_USE_MUTUAL_EXCLUSION    FALSE
#endif
/** @} */

/**
 * @name    SPI DMA modes
 * @{
 */
#define SPC5_SPI_DMA_NONE                   0
#define SPC5_SPI_DMA_RX_ONLY                1
#define SPC5_SPI_DMA_RX_AND_TX              2
/** @} */

/*===========================================================================*/
/**
 * @name SERIAL driver related setting
 * @{
 */
/*===========================================================================*/

/**
 * @name    SERIAL DMA modes
 * @{
 */
#define SPC5_SERIAL_DMA_OFF                 0
#define SPC5_SERIAL_DMA_ON                  1
/** @} */

/**
 * @name    LIN DMA modes
 * @{
 */
#define SPC5_LIN_DMA_OFF                    0
#define SPC5_LIN_DMA_ON                     1
/** @} */

/**
 * @name    LINFlex Mode Settings
 * @{
 */
#define SPC5_LINFLEX_MODE_NONE              0
#define SPC5_LINFLEX_MODE_SERIAL            1
#define SPC5_LINFLEX_MODE_LIN               2
/** @} */

/*
 * EDMA driver settings.
 */
#define SPC5_EDMA_CR_SETTING                (EDMA_CR_GRP1PRI(1) |           \
                                             EDMA_CR_GRP0PRI(0) |           \
                                             EDMA_CR_EMLM       |           \
                                             EDMA_CR_ERGA)
#define SPC5_EDMA1_GROUP0_PRIORITIES        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
#define SPC5_EDMA_COMBO_CH_ERR_IRQ_PRIO     10

/*
 * SERIAL driver system settings.
 */
#define SPC5_LINFLEX0_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX1_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX2_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX7_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX10_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX15_SETTING               SPC5_LINFLEX_MODE_NONE
#define SPC5_LINFLEX0_PRIORITY              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_LINFLEX1_PRIORITY              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_LINFLEX2_PRIORITY              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_LINFLEX7_PRIORITY              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_LINFLEX10_PRIORITY             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_LINFLEX15_PRIORITY             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_DMA_MODE                SPC5_SERIAL_DMA_OFF
#define SPC5_LIN_DMA_MODE                   SPC5_LIN_DMA_OFF

#define SPC5_SERIAL_LINFLEX0_TX_DMA_CH_ID   0
#define SPC5_SERIAL_LINFLEX0_RX_DMA_CH_ID   1
#define SPC5_SERIAL_LINFLEX1_TX_DMA_CH_ID   2
#define SPC5_SERIAL_LINFLEX1_RX_DMA_CH_ID   3
#define SPC5_SERIAL_LINFLEX2_TX_DMA_CH_ID   4
#define SPC5_SERIAL_LINFLEX2_RX_DMA_CH_ID   5
#define SPC5_SERIAL_LINFLEX7_TX_DMA_CH_ID   6
#define SPC5_SERIAL_LINFLEX7_RX_DMA_CH_ID   7
#define SPC5_SERIAL_LINFLEX10_TX_DMA_CH_ID  8
#define SPC5_SERIAL_LINFLEX10_RX_DMA_CH_ID  9
#define SPC5_SERIAL_LINFLEX15_TX_DMA_CH_ID  10
#define SPC5_SERIAL_LINFLEX15_RX_DMA_CH_ID  11
#define SPC5_SERIAL_LINFLEX0_DMA_IRQ_PRIO   INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_LINFLEX1_DMA_IRQ_PRIO   INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_LINFLEX2_DMA_IRQ_PRIO   INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_LINFLEX7_DMA_IRQ_PRIO   INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_LINFLEX10_DMA_IRQ_PRIO  INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_SERIAL_LINFLEX15_DMA_IRQ_PRIO  INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)

#define SPC5_LINFLEX0_RX_DMA_MUX            0U
#define SPC5_LINFLEX0_RX_DMA_DEV_ID         SPC5_LINFLEX0_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX0_TX_DMA_MUX            0U
#define SPC5_LINFLEX0_TX_DMA_DEV_ID         SPC5_LINFLEX0_TX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX1_RX_DMA_MUX            0U
#define SPC5_LINFLEX1_RX_DMA_DEV_ID         SPC5_LINFLEX1_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX1_TX_DMA_MUX            0U
#define SPC5_LINFLEX1_TX_DMA_DEV_ID         SPC5_LINFLEX1_TX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX2_RX_DMA_MUX            0U
#define SPC5_LINFLEX2_RX_DMA_DEV_ID         SPC5_LINFLEX2_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX2_TX_DMA_MUX            0U
#define SPC5_LINFLEX2_TX_DMA_DEV_ID         SPC5_LINFLEX2_TX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX7_RX_DMA_MUX            0U
#define SPC5_LINFLEX7_RX_DMA_DEV_ID         SPC5_LINFLEX7_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX7_TX_DMA_MUX            0U
#define SPC5_LINFLEX7_TX_DMA_DEV_ID         SPC5_LINFLEX7_TX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX10_RX_DMA_MUX           0U
#define SPC5_LINFLEX10_RX_DMA_DEV_ID        SPC5_LINFLEX10_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX10_TX_DMA_MUX           0U
#define SPC5_LINFLEX10_TX_DMA_DEV_ID        SPC5_LINFLEX10_TX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX15_RX_DMA_MUX           0U
#define SPC5_LINFLEX15_RX_DMA_DEV_ID        SPC5_LINFLEX15_RX_DMA_MUX0_DEV_ID
#define SPC5_LINFLEX15_TX_DMA_MUX           0U
#define SPC5_LINFLEX15_TX_DMA_DEV_ID        SPC5_LINFLEX15_TX_DMA_MUX0_DEV_ID

/*
 * PIT v2 driver system settings.
 */
#define SPC5_PIT_USE_PIT0                   TRUE
#define PIT0_CHANNEL_CH0_ENABLED			FALSE
#define PIT0_CHANNEL_CH1_ENABLED			FALSE
#define PIT0_CHANNEL_CH2_ENABLED			FALSE
#define PIT0_CHANNEL_CH3_ENABLED			FALSE
#define PIT0_CHANNEL_CH4_ENABLED			FALSE
#define PIT0_CHANNEL_CH5_ENABLED			FALSE
#define PIT0_CHANNEL_CH6_ENABLED			FALSE
#define PIT0_CHANNEL_CH7_ENABLED			FALSE
#define SPC5_PIT0_START_PCTL                (SPC5_ME_PCTL_RUN(2) |          \
                                             SPC5_ME_PCTL_LP(2))
#define SPC5_PIT0_STOP_PCTL                 (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#define SPC5_PIT0_CH0_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 4)
#define SPC5_PIT0_CH1_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH2_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH3_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH4_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH5_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH6_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)
#define SPC5_PIT0_CH7_IRQ_PRIO              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)

/*
 * STM driver system settings.
 */
#define SPC5_STM_USE_STM2                   FALSE
#define SPC5_STM2_SYSCLOCK_PRE              1
#define SPC5_STM2_CH0_ENABLED               FALSE
#define SPC5_STM2_CH0_IRQ_PRIORITY          INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 11)  
#define SPC5_STM2_CH1_ENABLED               FALSE
#define SPC5_STM2_CH1_IRQ_PRIORITY          INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 11)  
#define SPC5_STM2_CH2_ENABLED               FALSE
#define SPC5_STM2_CH2_IRQ_PRIORITY          INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 11)  
#define SPC5_STM2_CH3_ENABLED               FALSE
#define SPC5_STM2_CH3_IRQ_PRIORITY          INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 12)  

/*
 * SPI driver system settings.
 */
#define SPC5_SPI_USE_DSPI0                  FALSE
#define SPC5_SPI_USE_DSPI1                  FALSE
#define SPC5_SPI_USE_DSPI2                  FALSE
#define SPC5_SPI_USE_DSPI3                  FALSE

#define SPC5_SPI_DMA_MODE                   SPC5_SPI_DMA_NONE
#define SPC5_SPI_DSPI0_MCR                  (0U | SPC5_MCR_PCSIS0 | SPC5_MCR_PCSIS1 | SPC5_MCR_PCSIS2 | SPC5_MCR_PCSIS3 | SPC5_MCR_PCSIS4 | SPC5_MCR_PCSIS5 | SPC5_MCR_PCSIS6 | SPC5_MCR_PCSIS7)
#define SPC5_SPI_DSPI1_MCR                  (0U | SPC5_MCR_PCSIS0 | SPC5_MCR_PCSIS1 | SPC5_MCR_PCSIS2 | SPC5_MCR_PCSIS3 | SPC5_MCR_PCSIS4 | SPC5_MCR_PCSIS5 | SPC5_MCR_PCSIS6 | SPC5_MCR_PCSIS7)
#define SPC5_SPI_DSPI2_MCR                  (0U | SPC5_MCR_PCSIS0 | SPC5_MCR_PCSIS1 | SPC5_MCR_PCSIS2 | SPC5_MCR_PCSIS3 | SPC5_MCR_PCSIS4 | SPC5_MCR_PCSIS7)
#define SPC5_SPI_DSPI3_MCR                  (0U | SPC5_MCR_PCSIS0 | SPC5_MCR_PCSIS1 | SPC5_MCR_PCSIS2 | SPC5_MCR_PCSIS3 | SPC5_MCR_PCSIS4 | SPC5_MCR_PCSIS5 | SPC5_MCR_PCSIS6 | SPC5_MCR_PCSIS7)

#define SPC5_SPI_DSPI0_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SPI_DSPI1_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SPI_DSPI2_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SPI_DSPI3_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)

#define SPC5_SPI_DSPI0_RX_DMA_CH_ID         0
#define SPC5_SPI_DSPI0_TX1_DMA_CH_ID        1
#define SPC5_SPI_DSPI0_TX2_DMA_CH_ID        2
#define SPC5_SPI_DSPI1_RX_DMA_CH_ID         3
#define SPC5_SPI_DSPI1_TX1_DMA_CH_ID        4
#define SPC5_SPI_DSPI1_TX2_DMA_CH_ID        5
#define SPC5_SPI_DSPI2_RX_DMA_CH_ID         6
#define SPC5_SPI_DSPI2_TX1_DMA_CH_ID        7
#define SPC5_SPI_DSPI2_TX2_DMA_CH_ID        8
#define SPC5_SPI_DSPI3_RX_DMA_CH_ID         9
#define SPC5_SPI_DSPI3_TX1_DMA_CH_ID        10
#define SPC5_SPI_DSPI3_TX2_DMA_CH_ID        11

#define SPC5_SPI_DSPI0_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10) 
#define SPC5_SPI_DSPI1_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SPI_DSPI2_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SPI_DSPI3_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)

#define SPC5_DSPI0_RX_DMA_MUX               0U
#define SPC5_DSPI0_RX_DMA_DEV_ID            SPC5_DSPI0_RX_DMA_MUX0_DEV_ID
#define SPC5_DSPI0_TX1_DMA_MUX              0U
#define SPC5_DSPI0_TX1_DMA_DEV_ID           SPC5_DSPI0_TX1_DMA_MUX0_DEV_ID
#define SPC5_DSPI0_TX2_DMA_MUX              0U
#define SPC5_DSPI0_TX2_DMA_DEV_ID           SPC5_DSPI0_TX2_DMA_MUX0_DEV_ID
#define SPC5_DSPI1_RX_DMA_MUX               0U
#define SPC5_DSPI1_RX_DMA_DEV_ID            SPC5_DSPI1_RX_DMA_MUX0_DEV_ID
#define SPC5_DSPI1_TX1_DMA_MUX              0U
#define SPC5_DSPI1_TX1_DMA_DEV_ID           SPC5_DSPI1_TX1_DMA_MUX0_DEV_ID
#define SPC5_DSPI1_TX2_DMA_MUX              0U
#define SPC5_DSPI1_TX2_DMA_DEV_ID           SPC5_DSPI1_TX2_DMA_MUX0_DEV_ID
#define SPC5_DSPI2_RX_DMA_MUX               0U
#define SPC5_DSPI2_RX_DMA_DEV_ID            SPC5_DSPI2_RX_DMA_MUX0_DEV_ID
#define SPC5_DSPI2_TX1_DMA_MUX              0U
#define SPC5_DSPI2_TX1_DMA_DEV_ID           SPC5_DSPI2_TX1_DMA_MUX0_DEV_ID
#define SPC5_DSPI2_TX2_DMA_MUX              0U
#define SPC5_DSPI2_TX2_DMA_DEV_ID           SPC5_DSPI2_TX2_DMA_MUX0_DEV_ID
#define SPC5_DSPI3_RX_DMA_MUX               0U
#define SPC5_DSPI3_RX_DMA_DEV_ID            SPC5_DSPI3_RX_DMA_MUX0_DEV_ID
#define SPC5_DSPI3_TX1_DMA_MUX              0U
#define SPC5_DSPI3_TX1_DMA_DEV_ID           SPC5_DSPI3_TX1_DMA_MUX0_DEV_ID
#define SPC5_DSPI3_TX2_DMA_MUX              0U
#define SPC5_DSPI3_TX2_DMA_DEV_ID           SPC5_DSPI3_TX2_DMA_MUX0_DEV_ID


/*
 * I2S driver system settings.
 */
#define SPC5_I2S_USE_DSPI0                  FALSE
#define SPC5_I2S_USE_DSPI1                  FALSE
#define SPC5_I2S_USE_DSPI2                  FALSE
#define SPC5_I2S_USE_DSPI3                  FALSE

#define I2S_USE_WAIT                        TRUE

#define SPC5_I2S_DSPI0_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_I2S_DSPI1_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_I2S_DSPI2_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_I2S_DSPI3_IRQ_PRIO             INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)

#define SPC5_I2S_DSPI0_RX_DMA_CH_ID         0
#define SPC5_I2S_DSPI0_TX1_DMA_CH_ID        1
#define SPC5_I2S_DSPI0_TX2_DMA_CH_ID        2
#define SPC5_I2S_DSPI1_RX_DMA_CH_ID         3
#define SPC5_I2S_DSPI1_TX1_DMA_CH_ID        4
#define SPC5_I2S_DSPI1_TX2_DMA_CH_ID        5
#define SPC5_I2S_DSPI2_RX_DMA_CH_ID         6
#define SPC5_I2S_DSPI2_TX1_DMA_CH_ID        7
#define SPC5_I2S_DSPI2_TX2_DMA_CH_ID        8
#define SPC5_I2S_DSPI3_RX_DMA_CH_ID         9
#define SPC5_I2S_DSPI3_TX1_DMA_CH_ID        10
#define SPC5_I2S_DSPI3_TX2_DMA_CH_ID        11

#define SPC5_I2S_DSPI0_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10) 
#define SPC5_I2S_DSPI1_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_I2S_DSPI2_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_I2S_DSPI3_DMA_IRQ_PRIO         INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)


/*
 * I2C driver system settings.
 */

#define SPC5_I2C_IRQ_PRIORITY               INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10) 

/*
 * CAN SUBSYSTEM driver system settings.
 */
#define SPC5_USE_CAN_SUB_0_M_CAN_0          FALSE
#define SPC5_CAN_SUB_0_M_CAN_0_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_0_M_CAN_0_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_0_M_CAN_0_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_0_M_CAN_0_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_0_M_CAN_0_RAM_START    0UL	   
#define SPC5_CAN_SUB_0_M_CAN_0_RAM_SIZE     0UL
	
#define SPC5_USE_CAN_SUB_0_M_CAN_1          FALSE
#define SPC5_CAN_SUB_0_M_CAN_1_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_0_M_CAN_1_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_0_M_CAN_1_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_0_M_CAN_1_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_0_M_CAN_1_RAM_START	SPC5_CAN_SUB_0_M_CAN_0_RAM_START + SPC5_CAN_SUB_0_M_CAN_0_RAM_SIZE
#define SPC5_CAN_SUB_0_M_CAN_1_RAM_SIZE     0UL
	
#define SPC5_USE_CAN_SUB_0_M_CAN_2          FALSE
#define SPC5_CAN_SUB_0_M_CAN_2_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_0_M_CAN_2_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_0_M_CAN_2_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_0_M_CAN_2_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_0_M_CAN_2_RAM_START	SPC5_CAN_SUB_0_M_CAN_1_RAM_START + SPC5_CAN_SUB_0_M_CAN_1_RAM_SIZE
#define SPC5_CAN_SUB_0_M_CAN_2_RAM_SIZE     0UL
	
#define SPC5_USE_CAN_SUB_0_M_CAN_3          FALSE
#define SPC5_CAN_SUB_0_M_CAN_3_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_0_M_CAN_3_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_0_M_CAN_3_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_0_M_CAN_3_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_0_M_CAN_3_RAM_START	SPC5_CAN_SUB_0_M_CAN_2_RAM_START + SPC5_CAN_SUB_0_M_CAN_2_RAM_SIZE
#define SPC5_CAN_SUB_0_M_CAN_3_RAM_SIZE     0UL
	
	
#define SPC5_CAN_SUB_0_RAM_START_PTCL       (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_0_RAM_STOP_PTCL        (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
	
#define SPC5_USE_CAN_SUB_1_M_CAN_1          TRUE
#define SPC5_CAN_SUB_1_M_CAN_1_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_1_M_CAN_1_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_1_M_CAN_1_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_1_M_CAN_1_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_1_M_CAN_1_RAM_START    0UL	   
#define SPC5_CAN_SUB_1_M_CAN_1_RAM_SIZE     2645UL	   
	
#define SPC5_USE_CAN_SUB_1_M_CAN_2          FALSE
#define SPC5_CAN_SUB_1_M_CAN_2_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_1_M_CAN_2_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_1_M_CAN_2_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_1_M_CAN_2_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_1_M_CAN_2_RAM_START	SPC5_CAN_SUB_1_M_CAN_1_RAM_START + SPC5_CAN_SUB_1_M_CAN_1_RAM_SIZE
#define SPC5_CAN_SUB_1_M_CAN_2_RAM_SIZE     0UL
	
#define SPC5_USE_CAN_SUB_1_M_CAN_3          FALSE
#define SPC5_CAN_SUB_1_M_CAN_3_START_PTCL   (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_1_M_CAN_3_STOP_PTCL    (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
#define SPC5_CAN_SUB_1_M_CAN_3_L0_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)
#define SPC5_CAN_SUB_1_M_CAN_3_L1_PRIORITY  INTC_PSR_ENABLE(INTC_PSR_MAINCORE,10)	  
#define SPC5_CAN_SUB_1_M_CAN_3_RAM_START	SPC5_CAN_SUB_1_M_CAN_2_RAM_START + SPC5_CAN_SUB_1_M_CAN_2_RAM_SIZE
#define SPC5_CAN_SUB_1_M_CAN_3_RAM_SIZE     0UL
	
	
#define SPC5_CAN_SUB_1_RAM_START_PTCL       (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CAN_SUB_1_RAM_STOP_PTCL        (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))
/*
 * CAN SUBSYSTEM driver filter settings.
*/
/* MCAN filter configuration */
#define SPC5_CAN_SUB_MAX_STD_FILTERS          3
#define SPC5_CAN_SUB_MAX_XTD_FILTERS          5
#define SPC5_CAN_MAX_DATA_LENGHT			  8U	

/* MCAN DEBUG options */
#define CAN_DEBUG_RX_COUNTER                 FALSE
#define CAN_DEBUG_TX_COUNTER                 FALSE

/* CCCU system settings */
#define SPC5_CCCU_0_START_PTCL              (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_CCCU_0_STOP_PTCL               (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))

/*
 * SWT driver system settings.
 */
#define SPC5_SWT_USE_SWT2                   FALSE
#define SPC5_SWT2_IRQ_PRIORITY              INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 63)

#define SPC5_SWT2_CLOCK_SOURCE_OSC          TRUE
#define SPC5_SWT2_FREQUENCY                 16000000U
#define SPC5_SWT2_TIMEOUT_PERIOD            0
#define SPC5_SWT2_INTERRUPT_MODE            TRUE
#define SPC5_SWT2_PSEUDO_RANDOM_KEY         FALSE
#define SPC5_SWT2_WINDOW_MODE               FALSE
#define SPC5_SWT2_WINDOW_PERIOD             0
#define SPC5_SWT2_STOP_IN_STOP_MODE         FALSE
#define SPC5_SWT2_FREEZE_IN_DEBUG_MODE      TRUE
#define SPC5_SWT2_SYSTEM_RESET              FALSE

/*
 * SARADC driver system settings.
 */ 
#define SPC5_SARADC_USE_SARADC12_SV			TRUE
#define SPC5_SARADC12_SV_PRIORITY			INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SARADC12_SV_DMA_CH_ID          0
#define SPC5_SARADC12_SV_DMA_IRQ_PRIO       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 10)
#define SPC5_SARADC_USE_DMA                 FALSE
#define SPC5_SARADC_DMA_BUFFER_LENGHT       0U
#define SPC5_SARADC_MAX_NUMOFCHANNELS	    4U
#define SPC5_SARADC_MAX_NUMOFTHRESHOLDS     1U
#define SPC5_SARADC_DMA_ERROR_HOOK(saradcp) irqSysHalt()

#define SPC5_SARADC12_SV_DMA_MUX            0U
#define SPC5_SARADC12_SV_DMA_DEV_ID         SPC5_SARADC12_SV_DMA_MUX0_DEV_ID

/*
 * FCCU driver system settings.
 */
#define SPC5_FCCU_CONFIG_IRQ_PRIO           INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_FCCU_ALARM_IRQ_PRIO            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)

/*
 * eMIOS (PWM/ICU) driver system settings.
 */
#define SPC5_PWM_USE_EMIOS0_CH0             FALSE
#define SPC5_PWM_USE_EMIOS0_CH1             FALSE
#define SPC5_PWM_USE_EMIOS0_CH2             FALSE
#define SPC5_PWM_USE_EMIOS0_CH3             FALSE
#define SPC5_PWM_USE_EMIOS0_CH4             FALSE
#define SPC5_PWM_USE_EMIOS0_CH5             FALSE
#define SPC5_PWM_USE_EMIOS0_CH6             FALSE
#define SPC5_PWM_USE_EMIOS0_CH7             FALSE
#define SPC5_PWM_USE_EMIOS0_GROUP1          FALSE
#define SPC5_PWM_USE_EMIOS0_GROUP2          FALSE
#define SPC5_PWM_USE_EMIOS0_GROUP3          FALSE

#define SPC5_ICU_USE_EMIOS0_CH0             FALSE
#define SPC5_ICU_USE_EMIOS0_CH1             FALSE
#define SPC5_ICU_USE_EMIOS0_CH2             FALSE
#define SPC5_ICU_USE_EMIOS0_CH3             FALSE
#define SPC5_ICU_USE_EMIOS0_CH4             FALSE
#define SPC5_ICU_USE_EMIOS0_CH5             FALSE
#define SPC5_ICU_USE_EMIOS0_CH6             FALSE
#define SPC5_ICU_USE_EMIOS0_CH7             FALSE

#define SPC5_EMIOS0_GFR_F0F1_PRIORITY       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F2F3_PRIORITY       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F4F5_PRIORITY       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F6F7_PRIORITY       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F8F9_PRIORITY       INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F10F11_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F12F13_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F14F15_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F16F17_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F18F19_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F20F21_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F22F23_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F24F25_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F26F27_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F28F29_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_EMIOS0_GFR_F30F31_PRIORITY     INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)

#define SPC5_EMIOS0_GPRE_VALUE              20UL
#define SPC5_EMIOS0_START_PCTL              (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2))
#define SPC5_EMIOS0_STOP_PCTL               (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0))

/*
 * WKPU driver system settings.
 */
#define SPC5_WKPU_USE_WKPU0                 FALSE

#define SPC5_WKPU0_IRQ0_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_WKPU0_IRQ1_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_WKPU0_IRQ2_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SPC5_WKPU0_IRQ3_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)

/*
 * BCTU driver system settings.
 */
#define SPC5_BCTU_USE_EMIOS0_TRIGGER        FALSE
#define SPC5_BCTU_USE_PIT0_TRIGGER          FALSE

/*
 * RTC/API driver system settings.
 */
#define SCP5_RTC_RTC_IRQ_PRIORITY           INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#define SCP5_RTC_API_IRQ_PRIORITY           INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)

/*
 * CRC driver system settings.
 */
#define SPC5_CRC_USE_CRC0                   FALSE
#define SPC5_CRC_USE_CRC1                   FALSE
#define SPC5_CRC_USE_CRC2                   FALSE


#endif /* _LLDCONF_H_ */

/** @} */
