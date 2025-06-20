/*
 * can.h
 *
 *  Created on: Sep 3, 2024
 *      Author: shehans
 */

#include "can_lld_cfg.h"
#include "can_stack.h"

#include "input_elements.h"
#include "CANMatrix_FD_3.h"


#ifndef CAN_H_
#define CAN_H_

#ifdef __cplusplus
 extern"C"{
#endif

// =============== Temporary Debug Area ===============
uint8_t bms_rx ; 
//=====================================================


#define CAN_SEND_ID 0x50U
#define CAN_RECV_ID 0x20F00121U

CANTxFrame txf;
uint8_t can_message = 0;

/*Start the selected CAN Driver */
void CAN_init(void){
can_lld_start(&CAND7, &can_config_mcanconf_ext);
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

/* Call back function on CAN Reception */
void mcanconf_ext_rxcb(uint32_t msgbuf, CANRxFrame crfp) {
	if ((crfp.SID == EVCU_ID) && (crfp.IDE == CAN_ID_STD)) {
			//EVCU_get_msg(crfp);
		}

		if ((crfp.SID == DISP_ID) && (crfp.IDE == CAN_ID_STD)) {
			//DISP_get_msg(crfp);
		}
		if ((crfp.SID == PDU_ID) && (crfp.IDE == CAN_ID_STD)) {
			bms_rx++;
			PDU_getData_read(crfp);
		}
		if ((crfp.EID == FD3_MSG1_RXID) && (crfp.IDE == CAN_ID_XTD)) {
			get_FD3MSG1(crfp);
		}

		// if ((crfp.EID == FD3_MSG2_RXID) && (crfp.IDE == CAN_ID_XTD)) {
		// 	get_FD3MSG2(crfp);
		// }

		if ((crfp.EID == LH_ID) && (crfp.IDE == CAN_ID_XTD)) {
			Left_handle_msg(crfp);
			//LED_toggle;		//for relay controller board
		}

		if ((crfp.EID == RH_ID) && (crfp.IDE == CAN_ID_XTD)) {
			Right_handle_msg(crfp);
			
		}

	(void) msgbuf;
}

#ifdef __cplusplus
 }
#endif

#endif /* CAN_H_ */
