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

/*================HEADLIGHT MODULE IMPLEMENTATION======================*/

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
        highbeam->control_signal(true);
         lowbeam->state = false;
    }
    else{
         highbeam->control_signal(false);
         if(passbeam->evaluate_press()==true){
            passbeam->control_signal(true);
         }
         else{
            passbeam->control_signal(false);
            if(lowbeam->evaluate_press()==true){
                 lowbeam->control_signal(true);
            }
            else{
                lowbeam->control_signal(false);
            }
         }
    }
    highbeam->activate();
    lowbeam->activate();
    passbeam->activate();

}


/*================TURN SIGNAL MODULE IMPLEMENTATION======================*/

class TurnSignal_Module:public Module{
    private:
    public:
        TurnSignal_Module(Device* left,Device* right):leftsignal(left), rightsignal(right) {}
        Device* leftsignal;
        Device* rightsignal;
        void activate(void);
};

void TurnSignal_Module::activate(void){
   if(leftsignal->evaluate_press() == TRUE){
    rightsignal->state = false;
    leftsignal->control_signal(true);
   }
   if(rightsignal->evaluate_press()==TRUE){
     leftsignal->state = false;
     rightsignal->control_signal(true);
   }
   leftsignal->activate();
   rightsignal->activate();
}

/*===================HORN MODULE IMPLEMENTATION===================*/

class Horn_Module:public Module{
    private:
    public:
        Horn_Module(Device* horn):horn(horn) {}
        Device* horn;
        void activate(void);
};

void Horn_Module::activate(void){
    if(horn->evaluate_press()==true){
        horn->control_signal(true);
    }
    else{
         horn->control_signal(false);
    }
    horn->activate();
}


/*===================WIPER MODULE IMPLEMENTATION===================*/

class Wiper_Module:public Module{
    private:
    public:
        Wiper_Module(Device* wiper):wiper(wiper) {}
        Device* wiper;
        void activate(void);
};

void Wiper_Module::activate(void){
    if(wiper->evaluate_press()==true){
        wiper->control_signal(true);
    }
    else{
         wiper->control_signal(false);
    }
}
