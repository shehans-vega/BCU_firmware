#include "device_class.hpp"

class Module{
    private:
    public:
        Module(){}
        Device* main_device;
        // virtual void init(void);
        virtual void activate(void);
        // virtual void deactivate(void);

};

class HeadLight_Module:public Module{
    private:
    public:
        HeadLight_Module(Device* hb,Device* lb,Device* pb):highbeam(hb), lowbeam(lb), passbeam(pb) {}
        Device* highbeam;
        Device* lowbeam;
        Device* passbeam;
        void activate(void);
};

void HeadLight_Module::activate(void){
    if(highbeam->evaluate_press()==true){
        highbeam->control_signal();
    }
    else if(passbeam->evaluate_press()==true){
        passbeam->control_signal();
    }
    else if(lowbeam->evaluate_press()==true){
         lowbeam->control_signal();
    }
}
