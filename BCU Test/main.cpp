
extern"C"{
#include "mainc.h"
#include  "components.h"
}

int main(){
    
    mainc();
    for(;;){
        pal_lld_togglepad(PORT_LED1,LED1);
        pal_lld_togglepad(PORT_LED2,LED2);
         osalThreadDelayMilliseconds(140);

    }
}