#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdbool.h>
#include <stdint.h>

#define BUTTON_HOLD_THRESHOLD 500
#define BUTTON_PRESS_THRESHOLD 20
#define BUTTON_RELEASE_DELAY 50 // Delay threshold for the button to go to idle state

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
    uint16_t release_count;   // New counter for delay after button release
} buttonInput_t;

#ifdef __cplusplus
}
#endif

button_t button_state(buttonInput_t *button) {
    // Check mode button for long and short press
    switch (button->buttonState) {
        case BUTTON_IDLE:
            if (button->button_in == 1) {
                button->press_count++;
                if (button->press_count > BUTTON_PRESS_THRESHOLD) {
                    button->buttonState = BUTTON_PRESSED;
                    button->press_count = 0;
                }
            } else {
                button->press_count = 0;
            }
           
            button->hold_count = 0;
            button->release_count = 0; // Reset release counter in idle state
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
                button->buttonPrevState = BUTTON_HOLD;
            }
            break;

        case BUTTON_RELEASED:
            if (button->button_in == 0) {
                button->release_count++;
                if (button->release_count > BUTTON_RELEASE_DELAY) {
                    button->buttonState = BUTTON_IDLE;
					button->buttonPrevState = BUTTON_RELEASED;
                }
            } else {
                button->buttonState = BUTTON_PRESSED; // Button pressed again during release
                button->release_count = 0;             // Reset release counter
            }
            break;

        default:
            // Handle unexpected state
            button->buttonState = BUTTON_IDLE;
            break;
    }

    return button->buttonState;
}

#endif /* BUTTON_H_ */
