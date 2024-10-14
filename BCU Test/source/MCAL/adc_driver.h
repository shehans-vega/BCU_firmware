/*
 * adc_driver.h
 *
 *  Created on: Sep 3, 2024
 *      Author: shehans
 */

#include "saradc_lld_cfg.h"

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define NUMOFCHANNELS 4
uint32_t adc_value[NUMOFCHANNELS];
uint8_t anp[NUMOFCHANNELS] = {  13U, 49U ,17U, 39U};

void ADC_init(void){
	SARADCDriver* driverUnderTest;
	driverUnderTest = &SARADC12DSV;
	saradc_lld_start(driverUnderTest, &saradc_config_saradcconf);
	saradc_lld_start_conversion(driverUnderTest);
}

void saradcconf_conv_cb(SARADCDriver *saradcp) {
	// Read converted channels //
	for (uint8_t i = 0; i < NUMOFCHANNELS; i++) {
		adc_value[i] = saradc_lld_readchannel(saradcp, anp[i]);
	}
}

#ifdef __cplusplus
}
#endif

#endif /* ADC_DRIVER_H_ */
