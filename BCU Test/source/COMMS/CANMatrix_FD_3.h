/*
 * CANMatrix_FD_3.h
 *
 *  Created on: May 25, 2023
 *      Author: Chamath De Silva, Vega Innovations, Sri Lanka
 */

#ifndef CANMATRIX_FD_3_H_
#define CANMATRIX_FD_3_H_

#include <stdint.h>
#include "can_lld_cfg.h"

#define FD_MC_3  1  // migrate to a global fw configuration file

#if FD_MC_3

#define FD3_MSG1_RXID 0x10f8109A
#define FD3_MSG2_RXID 0x10f8108d

#endif

struct FD3_controller_status_struct
{
	uint8_t reserved2 :1;
	uint8_t reserved1 :1;
	uint8_t idle :1;
	uint8_t cruise :1;
	uint8_t speedmode :2;
	uint8_t gearState :2;
};

union FD3_controller_status_union
{
	uint8_t all;
	struct FD3_controller_status_struct bits;
};

struct FD3_work_status_struct
{
	uint8_t fault :1;
	uint8_t brake :1;
	uint8_t controllerState :1;
	uint8_t direction :1;
	uint8_t motorState :1;
	uint8_t rotation :1;
	uint8_t reserved2 :1;
	uint8_t reserved1 :1;
};

union FD3_work_status_union
{
	uint8_t all;
	struct FD3_work_status_struct bits;
};

struct FD3_error_code_struct
{
	uint16_t reserved :1;
	uint16_t peak_line_current :1;
	uint16_t MOSFET_lower :1;
	uint16_t MOSFET_upper :1;
	uint16_t line_current_zero :1;
	uint16_t phase_line_short :1;
	uint16_t phase_current_zero :1;
	uint16_t phase_current_overflow1 :1;
	uint16_t controller_overtemp :1;
	uint16_t motor_overtemp :1;
	uint16_t anti_theft :1;
	uint16_t voltage_fault :1;
	uint16_t phase_current_overflow2 :1;
	uint16_t current_protection :1;
	uint16_t throttle_fault :1;
	uint16_t motor_hall_fault :1;

};

union FD3_error_code_union
{
	uint16_t all;
	struct FD3_error_code_struct bit;
};

struct FD3_MSG1_struct
{
	uint16_t throttle;
	union FD3_controller_status_union FD3_controller_status;
	union FD3_work_status_union FD3_work_status;
	uint16_t RPM;
	uint8_t controller_temp;
	uint8_t motor_temp;
};

struct FD3_MSG2_struct
{
	uint16_t bus_voltage;
	int16_t bus_current;
	uint16_t lap_count;
	union FD3_error_code_union error_code;

};

volatile struct FD3_MSG1_struct FD3_MSG1;
volatile struct FD3_MSG2_struct FD3_MSG2;

void get_FD3MSG1(CANRxFrame crfp)
{
	FD3_MSG1.FD3_controller_status.all = crfp.data8[0];
	FD3_MSG1.throttle = ((crfp.data8[2] << 8) | (crfp.data8[1]));
	FD3_MSG1.FD3_work_status.all = crfp.data8[3];
	FD3_MSG1.RPM = ((crfp.data8[5] << 8) | (crfp.data8[4]));
	FD3_MSG1.motor_temp = crfp.data8[6] - 40; //-40 offset
	FD3_MSG1.controller_temp = crfp.data8[7] - 40; //-40 offset

	if (FD3_MSG1.FD3_controller_status.bits.speedmode == 0) {
		currentMode = ecoMode;
	}
	if (FD3_MSG1.FD3_controller_status.bits.speedmode == 1) {
		currentMode = normalMode;
	}
	if (FD3_MSG1.FD3_controller_status.bits.speedmode == 2) {
		currentMode = sportMode;
	}
}

void get_FD3MSG2(CANRxFrame crfp)
{
	FD3_MSG2.bus_voltage = ((crfp.data8[1] << 8) | (crfp.data8[0]));
	FD3_MSG2.bus_current = ((crfp.data8[3] << 8) | (crfp.data8[2]));
	FD3_MSG2.lap_count = ((crfp.data8[5] << 8) | (crfp.data8[4]));
	FD3_MSG2.error_code.all = ((crfp.data8[7] << 8) | (crfp.data8[6]));
}
#endif /* CANMATRIX_FD_3_H_ */
