#include <xc.h>
#include "hardware.h"

#define _XTAL_FREQ   4000000 

void InituC()
{    	
    ANSEL  = 0x00;              /* Set the ports as digital I/O's          */
	ADCON0 = 0x00;		        /* Shut down ADC                           */
	CMCON  = 0x07;		        /* Shut down Comparator                    */
	VRCON  = 0x00;	            /* Disable reference Voltage               */
	TRISIO = 0x00;              /* Sets all of ports as outputs            */
	GPIO   = 0x00;              /* Sets all of pins in low level           */
    
    TRISIO2 = 1;                /* Set GP2 (Pin 5) as input                */

	INTCON     |= 0x90;         /* Enable Global and EXT interrupt         */
	OPTION_REG |= 0x40;         /* Make EXT interrupt as posedge triggered */
    
    /* Sets GP1 (Pin 6) in nessesary conditions */
    GP0     = 0;           /* Low level on GP1 (Pin 6)                     */
    
    /* Sets GP4 (Pin 3) in nessesary conditions */
    GP4     = 1;           /* High level on GP4 (Pin 3)                    */
    
    /* Sets GP5 (Pin 2) in nessesary conditions */
    GP5     = 0;           /* Low level on GP5 (Pin 2)                     */
    
   
}

void ButtonEvent()    /* Toggles to another state necessary ports */
{
       GP4 = ~GP4;
       GP5 = ~GP5;
       GP0 = ~GP0;  
}

void __interrupt() ISR(void)
{
	if(INTF)           /* If is EXT interrupt         */
	{
		ButtonEvent(); /* Calls to necessary function */
		INTF = 0;      /* Clear the interrupt         */
	}
}