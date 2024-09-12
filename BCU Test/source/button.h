/*
 * button.h
 *
 *  Created on: 10 Jul 2024
 *      Author: Chamath De Silva
 */


#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdbool.h>

#define BUTTON_HOLD_THRESHOLD 250
#define BUTTON_PRESS_THRESHOLD 20

typedef enum {
	BUTTON_IDLE, BUTTON_PRESSED, BUTTON_HOLD, BUTTON_RELEASED
} button_t;

button_t buttonState = BUTTON_IDLE;

bool mode_press = false;
bool mode_hold = false;

typedef struct {
	uint8_t button_in;
	uint8_t buttonState;
	uint8_t buttonPrevState;
	uint16_t press_count;
	uint16_t hold_count;
} buttonInput_t;


uint8_t button_state(buttonInput_t *button) {
//=============================================================== check mode button for long and short press ==================================================
	switch (button->buttonState) {
	case BUTTON_IDLE:
		if (button->button_in == 1) {
			button->press_count++;
			if (button->press_count > BUTTON_PRESS_THRESHOLD) { //  change for sensitivity
				button->buttonState = BUTTON_PRESSED;
				button->press_count = 0;
			}
		}
		button->buttonPrevState = BUTTON_IDLE;
		button->hold_count = 0;
		break;

	case BUTTON_PRESSED:
		if (button->button_in == 1) {
			if (button->hold_count < BUTTON_HOLD_THRESHOLD) {
				button->hold_count++;
			} else {
				button->buttonState = BUTTON_HOLD;
			}
		} else {
			button->buttonState = BUTTON_RELEASED;
			button->buttonPrevState = BUTTON_PRESSED;
		}
		break;

	case BUTTON_HOLD:
		if (button->button_in == 0) {
			button->buttonState = BUTTON_RELEASED;
		}
		break;

	case BUTTON_RELEASED:
		if (button->button_in == 0) {
			button->buttonState = BUTTON_IDLE;
		}
		break;
	}

	return button->buttonState;
}

#endif /* BUTTON_H_ */
