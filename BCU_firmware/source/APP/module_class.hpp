#include "device_class.hpp"
#include "CANMatrix_pdu.h"
#include "CANMatrix_FD_3.h"

// =================Temporary Debug Area =================
uint8_t debug_pass = 0;
uint8_t debug_hbeam;
uint8_t debug_lpress;
uint8_t debug_spress;
uint8_t debug_mtr_temp=0;
uint8_t debug_ctrl_temp = 0;
//========================================================

// ========== PATCH VARIABLES =======
bool hbeam_state = false;

//===================================

class Module
{
private:
public:
    Module() {}
    Device *main_device;
    // virtual void init(void);
    virtual void activate(void);
    // virtual void deactivate(void);
};

/*================HEADLIGHT MODULE IMPLEMENTATION======================*/

class HeadLight_Module : public Module
{
private:
public:
    HeadLight_Module(Device *hb, Device *lb, Device *pb) : highbeam(hb), lowbeam(lb), passbeam(pb) {}
    Device *highbeam;
    Device *lowbeam;
    Device *passbeam;
    void activate(void);
};

void HeadLight_Module::activate(void)
{

    if (evaluate_long_press(this->highbeam->device_button) == true)
    {
        hbeam_state = !hbeam_state;
        highbeam->control_signal(hbeam_state);
        highbeam->activate();
        debug_lpress++;
        this->highbeam->device_button->buttonState = BUTTON_IDLE;
        this->highbeam->device_button->buttonState = BUTTON_IDLE;
    }
    if (evaluate_short_press(this->highbeam->device_button) == true)
    {
        this->highbeam->device_button->buttonState = BUTTON_IDLE;
        this->highbeam->device_button->buttonState = BUTTON_IDLE;
        debug_spress++;

        highbeam->device_channel->state = false;
        hbeam_state  = false;
        highbeam->device_channel->activate();
        lowbeam->control_signal(true);
        lowbeam->activate();
    }

    if (hbeam_state == false)
    {
        if (passbeam->evaluate_press() == true)
        {
            debug_pass++;
            highbeam->device_channel->state = true;
            highbeam->device_channel->activate();
        }
        else
        {
            highbeam->device_channel->state = false;
            highbeam->device_channel->activate();
        }
    }
}

/*================TURN SIGNAL MODULE IMPLEMENTATION======================*/

class TurnSignal_Module : public Module
{
private:
public:
    TurnSignal_Module(Device *left, Device *right) : leftsignal(left), rightsignal(right) {}
    Device *leftsignal;
    Device *rightsignal;
    void activate(void);
};

void TurnSignal_Module::activate(void)
{
    if (leftsignal->evaluate_press() == TRUE)
    {
        rightsignal->state = false;
        leftsignal->control_signal(true);
    }
    if (rightsignal->evaluate_press() == TRUE)
    {
        leftsignal->state = false;
        rightsignal->control_signal(true);
    }
    leftsignal->activate();
    rightsignal->activate();
}

/*===================HORN MODULE IMPLEMENTATION===================*/

class Horn_Module : public Module
{
private:
public:
    Horn_Module(Device *horn) : horn(horn) {}
    Device *horn;
    void activate(void);
};

void Horn_Module::activate(void)
{
    if (horn->evaluate_press() == true)
    {
        horn->control_signal(true);
    }
    else
    {
        horn->control_signal(false);
    }
    horn->activate();
}

/*===================WIPER MODULE IMPLEMENTATION===================*/

class Wiper_Module : public Module
{
private:
public:
    Wiper_Module(Device *wiper) : wiper(wiper) {}
    Device *wiper;
    void activate(void);
};

void Wiper_Module::activate(void)
{
    if (wiper->evaluate_press() == true)
    {
        wiper->control_signal(true);
    }
    else
    {
        wiper->control_signal(false);
    }
}

/*===================PDU_FAN MODULE IMPLEMENTATION===================*/

#define MOTOR_TEMP_H 70
#define MOTOR_TEMP_L 55

#define CTRL_TEMP_H 60
#define CTRL_TEMP_L 50

bool bms_fan = false;
bool motor_fan = false;
bool ctrlr_fan = false;
bool fan_state = false;

class PDU_FAN_Module : public Module
{
private:
public:
    PDU_FAN_Module(Device *fan) : fan(fan){}
    Device *fan;
    void activate(void);
};

void PDU_FAN_Module :: activate(void){
    uint8_t motor_temp = (get_motor_temp() >> 8 ) & 0xFF;
    uint8_t ctrl_temp = (get_motor_temp()) & 0xFF;
    debug_mtr_temp = motor_temp;
    debug_ctrl_temp = ctrl_temp;
    if(motor_temp>=MOTOR_TEMP_H){
        motor_fan = true;
    }
    if(motor_temp<=MOTOR_TEMP_L){
        motor_fan = false;
    }
    if(ctrl_temp>=CTRL_TEMP_H){
        ctrlr_fan = true;
    }
    if(ctrl_temp<=CTRL_TEMP_L){
        ctrlr_fan = false;
    }
    bms_fan = get_bms_fan_state();
    fan_state = bms_fan || motor_fan || ctrlr_fan;
  this->fan->state = fan_state;
  this->fan->activate();
}
