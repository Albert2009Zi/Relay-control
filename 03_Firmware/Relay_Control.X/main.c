/*
 * File:   main.c
 * Authors: Albert Ziatdinov, Alex Talko 
 *
 * Created on 27.06.2022, 19:46
 */

#include <xc.h>
#include "hardware.h"

//#define SIMULATION

#ifndef SIMULATION
// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#else 
// Config word
__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & BOREN_ON & CP_OFF & CPD_OFF);

#endif

void main(void) 
{   
   InituC();  
  
   while(1)
    { 
    }
}
