/*
 * input_elements.h
 *
 *  Created on: Sep 11, 2024
 *      Author: shehans
 */
#include "button.h"

#ifndef INPUT_ELEMENTS_H_
#define INPUT_ELEMENTS_H_

buttonInput_t passButton;
buttonInput_t highbeamButton;
buttonInput_t lowbeamButton;
buttonInput_t wiperButton;
buttonInput_t leftButton;
buttonInput_t rightButton;
buttonInput_t hornButton;

void inputs(void){
	can_decode();
	proceses_buttons();
		}

void proceses_buttons(){
	button_state(&hornButton);
	button_state(&leftButton);
}

void can_decode(){
	if (L_handle_msg.fixset1.bit.horn == 1) {
				hornButton.button_in = 1;
			} else {
				hornButton.button_in = 0;
			}

			if (L_handle_msg.fixset1.bit.wiper == 1) {
				wiperButton.button_in = 1;

			} else {
				wiperButton.button_in = 0;
			}

			 if (L_handle_msg.fixset1.bit.head_lamp == 1) {
				 highbeamButton.button_in = 1;
			 }
			 else if (L_handle_msg.fixset1.bit.head_lamp == 2) {
					 lowbeamButton.button_in = 1;}
			 else {
				 highbeamButton.button_in = 0;
				 lowbeamButton.button_in = 0;
			 }

			if (L_handle_msg.fixset1.bit.pass == 1) {
				passButton.button_in = 1;

			} else {
				passButton.button_in = 0;
			}

			 if (L_handle_msg.fixset1.bit.turn == 2) {
			 leftButton.button_in = 1;

			 } else {
			 leftButton.button_in = 0;
			 }
			 if (L_handle_msg.fixset1.bit.turn == 1) {
			 rightButton.button_in = 1;

			 } else {
			 rightButton.button_in = 0;
			 }
}

#endif /* INPUT_ELEMENTS_H_ */

