#include "hardware.h"

//#define SIMULATION

#ifndef SIMULATION
// CONFIG
#pragma config FOSC  = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE  = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP    = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD   = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#else 
// Config word
__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & BOREN_ON & CP_OFF & CPD_OFF);

#endif

// Define LED pin
#define GREEN_LED      GP5
#define RED_LED        GP4
#define RELAY_SWITCH   GP0

extern bool stateChangeFlag;

void initUc(void){
    ei();
    ANSEL   = 0x00;              /* Set the ports as digital I/O's          */
	ADCON0  = 0x00;		        /* Shut down ADC                           */
	CMCON   = 0x07;		        /* Shut down Comparator                    */
	VRCON   = 0x00;	            /* Disable reference Voltage               */
    
    
    TRISIO4 = 0;           /* Set GP4 (Pin 3) as output                    */
    TRISIO5 = 0;           /* Set GP5 (Pin 2) as output                    */
    TRISIO0 = 0;
    TRISIO2 = 1;

    GPIO = 0;   
    
    __delay_ms(20); 
    
    if (eeprom_read(0x00) == 0x0B && eeprom_read(0x01) == 0xFF){
		GREEN_LED     = 1;
        RED_LED       = 0;
        RELAY_SWITCH  = 0; 
    }
    else 
    { 
        GPIO = eeprom_read(0x01);
    }
       
}



// Main function
int main()
{	
    initUc();
    
    __delay_ms(20); 
    eeprom_write (0x00, 0x0B);
    __delay_ms(20); 
    
    IRQConfig();
	while(1)
    {  
        if (stateChangeFlag == true){
           eeprom_write (0x01, GPIO);
           __delay_ms(20);
           stateChangeFlag = false;
        }      
    }
}