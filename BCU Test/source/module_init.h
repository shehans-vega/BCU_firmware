#ifndef _MODULE_INIT_H
#define _MODULE_INIT_H

#include "input_elements.h"
#include "modules.h"
#include "output_elements.h"

moduleType hornModule;
moduleType wiperModule;
moduleType highbeamModule;
moduleType lowbeamModule;
moduleType passModule;
moduleType leftsignalModule;
moduleType rightsignalModule;

void initialize_modules(void){
 initialize(&hornModule, &hschannels[2], &hornButton, 0,0,init,activate_toggle,NULL );
}

void activate_modules(void){
	hornModule.activate(&hornModule);
}

#endif
