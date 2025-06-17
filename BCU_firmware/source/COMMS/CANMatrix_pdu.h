/*
 * CANMatrix_pdu.h
 *
 *  Created on: Jun 25, 2021
 *      Author: Nisal Bulathsinghalage, Vega Innovations, Sri Lanka
 *      Edited by: Chamath De Silva, Vega Innovations, Sri Lanka
 */

#ifndef CANMATRIX_PDU_H_
#define CANMATRIX_PDU_H_

#include "can_lld_cfg.h"

#define PDU_ID 0x32

struct PDU_fixSetG_struct {

	uint8_t cell_dev__error :1;
	uint8_t over_charge_current_error :1;
	uint8_t over_discharge_current_error :1;
	uint8_t communication_error :1;
	uint8_t bat_temp_error :1;
	uint8_t contactor_feedback_error :1;
	uint8_t precharger__error :1;
	uint8_t cell_lv_error :1;

};

struct charger_fixSetG_struct {
	uint8_t reserved3 :1;
	uint8_t reserved2 :1;
	uint8_t chiller :1;
	uint8_t low_SOC :1;
	uint8_t over_temp :1;
	uint8_t charge_current_lim :1;
	uint8_t cv_mode :1;
	uint8_t charge_complete_flag :1;
};

struct PDU_fixSetS_struct {
	uint8_t reserved1 :1;
	uint8_t GBT_connected :1;
	uint8_t fireMode :1;
	uint8_t charger_connected :1;
	uint8_t EVCU_state :4;

};

union charger_fixSetG_union {
	uint8_t all;
	struct charger_fixSetG_struct bit;
};

union PDU_fixSetG_union {
	uint8_t all;
	struct PDU_fixSetG_struct bit;
};
union PDU_fixSetS_union {
	uint8_t all;
	struct PDU_fixSetS_struct bit;
};

//----------------------------------------------------------
//						GET DATA
//----------------------------------------------------------

struct PDU_getData {
	uint16_t dataID;
	union PDU_fixSetG_union fixSetG;
	uint8_t op_mode;
	uint16_t lowest_cell_voltage;
	uint16_t highest_cell_voltage;
	uint8_t highest_pack_temparature;
	uint8_t Battery_cap;
	union charger_fixSetG_union chg_fixSetG;
	uint16_t total_pack_voltage;
	int16_t DC_current;
	uint8_t charge_status;
	uint8_t trip_event;
	uint8_t trip_val;
	uint8_t SOC;
	uint8_t SOH;
};
uint8_t tf = 0;
//----------------------------------------------------------
//						SET DATA
//----------------------------------------------------------

struct PDU_setData {
	uint16_t dataID;
	union PDU_fixSetS_union fixSetS;
	uint8_t contactor_on;
	uint8_t contactor_on_inverse;
	uint8_t set_op_mode;
	uint8_t cell_balancing_enable;
};

struct PDU_getData PDU_getData_i;
struct PDU_setData PDU_setData_i;

void PDU_getData_read(CANRxFrame crfp) {
	PDU_getData_i.dataID = crfp.data8[0];
	PDU_getData_i.fixSetG.all = crfp.data8[1];

	if (PDU_getData_i.dataID == 0) {
		PDU_getData_i.op_mode = crfp.data8[2];
		PDU_getData_i.lowest_cell_voltage = ((crfp.data8[4] << 8)
				| crfp.data8[3]);
		PDU_getData_i.highest_cell_voltage = ((crfp.data8[6] << 8)
				| crfp.data8[5]);
		PDU_getData_i.highest_pack_temparature = crfp.data8[7];
	}

	else if (PDU_getData_i.dataID == 1) {
		PDU_getData_i.Battery_cap = crfp.data8[4];
		PDU_getData_i.chg_fixSetG.all = crfp.data8[5];
		PDU_getData_i.total_pack_voltage = ((crfp.data8[7] << 8)
				| (crfp.data8[6]));
	}

	else if (PDU_getData_i.dataID == 2) {
		PDU_getData_i.trip_event = crfp.data8[2];
		PDU_getData_i.trip_val = crfp.data8[3];
		PDU_getData_i.DC_current = ((crfp.data8[5] << 8) | crfp.data8[4]);
		PDU_getData_i.SOC = crfp.data8[6];
		PDU_getData_i.SOH = crfp.data8[7];
	}

	if (tf == 1) {
		PDU_getData_i.fixSetG.bit.communication_error = 1;
	} else {
		PDU_getData_i.fixSetG.bit.communication_error = 0;
	}
}

bool get_bms_fan_state(){
       return PDU_getData_i.chg_fixSetG.bit.chiller;
}

#endif /* CANMATRIX_PDU_H_ */