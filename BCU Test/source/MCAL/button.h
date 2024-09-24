#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdbool.h>
#include <stdint.h>

#define BUTTON_HOLD_THRESHOLD 250
#define BUTTON_PRESS_THRESHOLD 20

#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
	BUTTON_IDLE, BUTTON_PRESSED, BUTTON_HOLD, BUTTON_RELEASED
} button_t;

typedef struct {
	uint8_t button_in;
	button_t buttonState;
	button_t buttonPrevState;
	uint16_t press_count;
	uint16_t hold_count;
} buttonInput_t;

#ifdef __cplusplus
}
#endif

uint8_t button_state(buttonInput_t *button) {
	//=============================================================== check mode button for long and short press ==================================================
	switch (button->buttonState) {
	case BUTTON_IDLE:
		if (button->button_in == 1) {
			button->press_count++;
			if (button->press_count > BUTTON_PRESS_THRESHOLD) { // change for sensitivity
				button->buttonState = BUTTON_PRESSED;
				button->press_count = 0;
			}
		} else {
			button->press_count = 0;  // Reset press count when button is not pressed
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
