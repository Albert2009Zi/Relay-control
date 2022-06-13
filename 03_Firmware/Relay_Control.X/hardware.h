/* 
 * File:   hardware.h
 * Author: User
 *
 * Created on 12 ???? 2022 ?., 22:06
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

void InituC(void);            /* uC initialisation after power on */
void ButtonEvent(void);       /* Event after button pushing       */ 
void __interrupt() ISR(void);


#endif	/* HARDWARE_H */

