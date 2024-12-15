/*
 * input_elements.h
 *
 *  Created on: Sep 11, 2024
 *      Author: shehans
 */

#ifndef INPUT_ELEMENTS_H_
#define INPUT_ELEMENTS_H_

#include "button.h"
#include "can_stack.h"

#define NUM_BUTTONS 7

#ifdef __cplusplus
extern "C"
{
#endif
  
      enum{
        LEFT_BTN,
        RGT_BTN,
        HLAMP_BTN,
        WIPER_BTN,
        HRN_BTN,
        PASS_BTN,
    }button_id;

    buttonInput_t buttons[NUM_BUTTONS];
    // temporary
    buttonInput_t hbeam_btn;
    //

    void can_decode()
    {
        uint8_t L_flags = (uint8_t)(L_handle_msg.fixset1.all);
        buttons[HRN_BTN].button_in = (L_flags & (1 << HRN_BTN)) ? 1 : 0;
        buttons[WIPER_BTN].button_in = (L_flags & (1 << WIPER_BTN)) ? 1 : 0;
        hbeam_btn.button_in = (L_flags & (1 << HLAMP_BTN)) ? 1 : 0;
        buttons[PASS_BTN].button_in = (L_flags & (1 << PASS_BTN)) ? 1 : 0;
        buttons[LEFT_BTN].button_in = (L_flags & (1 << LEFT_BTN)) ? 1 : 0;
        buttons[RGT_BTN].button_in = (L_flags & (1 << RGT_BTN)) ? 1 : 0;
    }

    void inputs(void)
    {
        can_decode();
    }

#ifdef __cplusplus
}
#endif

#endif /* INPUT_ELEMENTS_H_ */
