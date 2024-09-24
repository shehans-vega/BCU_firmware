#include "device_class.hpp"

class Module{
    private:
    public:
        Module();
        Device main_device;
        virtual void init(void);
        virtual void activate(void);
        virtual void deactivate(void);

};

class HeadLight:public Module{
    private:
    public:
        HeadLight(Device* hb,Device* lb,Device* pb):highbeam(hb),lowbeam(lb),passbeam(pb){}
        Device* highbeam;
        Device* lowbeam;
        Device* passbeam;
        void activate(void);
};

void HeadLight::activate(void){
    if(evaluate_latch(highbeam)== true){
        
    }
}
