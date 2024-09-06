/*
 * can.h
 *
 *  Created on: Sep 3, 2024
 *      Author: shehans
 */

#include "can_lld_cfg.h"

#ifndef CAN_H_
#define CAN_H_

#define CAN_SEND_ID 0x50U
#define CAN_RECV_ID 0x27U

CANTxFrame txf;

uint8_t can_message = 0;

/*Start the selected CAN Driver */
void CAN_init(void){
can_lld_start(&CAND7, &can_config_mcanconf);
/* TRANSMIT CAN FRAME CONFIGURATION */
txf.TYPE = CAN_ID_STD;
txf.ID = CAN_SEND_ID;
txf.DLC = 8U;
txf.data8[0] = 10U;
}

/* Transmit the CAN frame */
void CAN_send(void){
can_lld_transmit(&CAND7, CAN_ANY_TXBUFFER, &txf);
}

/* Receive CAN Frames */
void CAN_get(CANRxFrame crfp){
	can_message = crfp.data8[0];
}

void mcanconf_rxcb(uint32_t msgbuf, CANRxFrame crfp) {
	if ((crfp.SID == CAN_RECV_ID) && (crfp.IDE == CAN_ID_STD)) {
		CAN_get(crfp);
	}
	(void) msgbuf;
}

#endif /* CAN_H_ */
