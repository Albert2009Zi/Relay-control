#include "hardware.h"

bool stateChangeFlag = false;

void IRQConfig(){
    INTCONbits.INTE       = 1;
    OPTION_REGbits.INTEDG = 1;
    INTCONbits.GIE        = 1;
}


void ButtonEvent(){    /* Toggles to another state ports */
    
       GP4 = ~GP4;
       GP5 = ~GP5;
       GP0 = ~GP0;  
}

void __interrupt() BtnInterrupt(){
    
	if(INTF) {          /* If is EXT interrupt         */
		ButtonEvent(); /* Calls to necessary function */
		INTF = 0;      /* Clear the interrupt         */
	}
   stateChangeFlag = true;
}


