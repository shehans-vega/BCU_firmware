/*
 * can.h
 *
 *  Created on: Sep 3, 2024
 *      Author: shehans
 */

#include "can_lld_cfg.h"

#ifndef CAN_H_
#define CAN_H_

CANTxFrame txf;
CANRxFrame rxf;

/*Start the selected CAN Driver */
can_lld_start(&CAND2, &can_config_mcanconf);

/* TRANSMIT CAN FRAME */
txf.TYPE = CAN_ID_STD;
txf.ID = 0x7f0U;
txf.DLC = 8U;
txf.data32[0] = 0xDDEEFFAAUL;

/* Transmit the CAN frame */
can_lld_transmit(&CAND2, CAN_ANY_TXBUFFER, &txf);

/* Receive CAN Frames */
can_lld_receive(&CAND2, CAN_FIFO0_RXBUFFER, &rxf);



#endif /* CAN_H_ */
