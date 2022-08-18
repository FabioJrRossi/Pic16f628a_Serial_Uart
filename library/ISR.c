/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Interrupt service routine implementation.
 */

#include "Includes.h"   // Include for use of the librarys.

// Interrupt service routine.
void __interrupt() ISR(void) {
	if(RCIF) {  // If serial receive (Rx) interrupt.
		if(OERR) { // If over run error, then reset the receiver.
		
			CREN = 0;   
			CREN = 1;
		}
		SerialSendByte(RCREG);	// Echo back received char
	}
}