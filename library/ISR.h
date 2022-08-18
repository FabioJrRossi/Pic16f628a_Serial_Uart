/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Interrupt service routine header.
 */

#ifndef __ISR_H     // Conditional compilation, if macro __ISR_H is already defined, don't include this library again.
#define __ISR_H     // Macro for this file.

// Function prototype for interrupt service routine.
void __interrupt() ISR(void);       

#endif      // End ifndef.