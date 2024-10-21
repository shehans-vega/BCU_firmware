#include "device_class.hpp"

bool left;
bool right;
bool invert_r;
bool invert_l;
bool eval_left;
bool eval_right;

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
    if (highbeam->evaluate_press() == true)
    {
        highbeam->control_signal(true);
        lowbeam->state = false;
    }
    else
    {
        highbeam->control_signal(false);
        if (passbeam->evaluate_press() == true)
        {
            passbeam->control_signal(true);
        }
        else
        {
            passbeam->control_signal(false);
            if (lowbeam->evaluate_press() == true)
            {
                lowbeam->control_signal(true);
            }
            else
            {
                lowbeam->control_signal(false);
            }
        }
    }
    highbeam->activate();
    lowbeam->activate();
    passbeam->activate();
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
    static bool left_button_prev = false;  // Previous state of left button
    static bool right_button_prev = false; // Previous state of right button

    // Get the current button states
    bool left_button_curr = leftsignal->evaluate_press();
    bool right_button_curr = rightsignal->evaluate_press();

    if ((!left_button_curr && left_button_prev) || (left_button_curr && !left_button_prev))
    {

        if (!leftsignal->state == true)
        {
            leftsignal->control_signal(true);
            rightsignal->control_signal(false);
        }
        else
        {
            leftsignal->control_signal(false);
        }
    }

    if ((!right_button_curr && right_button_prev) || (right_button_curr && !right_button_prev))
    {

        if (!rightsignal->state == true)
        {
            rightsignal->control_signal(true);
            leftsignal->control_signal(false);
        }
        else
        {
            rightsignal->control_signal(false);
        }
    }

    left_button_prev = left_button_curr;
    right_button_prev = right_button_curr;

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
