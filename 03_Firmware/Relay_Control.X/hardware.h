/* 
 * File:   hardware.h
 * Author: User
 *
 * Created on 12 ???? 2022 ?., 22:06
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// Define CPU Frequency
// This must be defined, if __delay_ms() or 
// __delay_us() functions are used in the code
#define _XTAL_FREQ   4000000    

void ButtonEvent(void);       /* Event after button pushing       */ 
void IRQConfig(void);
void __interrupt() BtnInterrupt(void);

#endif	/* HARDWARE_H */

