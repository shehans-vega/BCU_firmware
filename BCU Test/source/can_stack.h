/*
 * CAN_Stack.h
 *
 *  Created on: Apr 30, 2024
 *      Author: Yohan Harshamal
 */

#ifndef SOURCE_CAN_STACK_H_
#define SOURCE_CAN_STACK_H_

#define EVCU_ID 0x91
#define DISP_ID 0x92
#define LH_ID 0xCF00121
#define LH_ID_TEST 0x27
#define RH_ID 0x8F00120

struct struct_R {
	uint8_t D :1;
	uint8_t max_regen :1;
	uint8_t regen :1;
	uint8_t page :1;
	uint8_t mode :2;
	uint8_t reverse :1;
	uint8_t IGN_N :1;
};

union union_R {
	uint8_t all;
	struct struct_R bit;
};

struct R_handle_struct {
	union union_R fixset1;
};

struct struct_L {
	uint8_t reserved :1;
	uint8_t pass :1;
	uint8_t horn :1;
	uint8_t wiper :1;
	uint8_t head_lamp :2;
	uint8_t turn :2;
};

union union_L {
	uint8_t all;
	struct struct_L bit;
};

struct L_handle_struct {
	union union_L fixset1;
};

volatile struct R_handle_struct R_handle_msg;
volatile struct L_handle_struct L_handle_msg;

void Right_handle_msg(CANRxFrame crfp) {
	R_handle_msg.fixset1.all = crfp.data8[0];
}

void Left_handle_msg(CANRxFrame crfp) {
	L_handle_msg.fixset1.all = crfp.data8[0];
}

#endif /* SOURCE_CAN_STACK_H_ */
