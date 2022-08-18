/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Serial (UART) library header.
 */

#ifndef __UART_H        // Conditional compilation, if macro __UART.H is already defined, don't include this library again.
#define __UART_H        // Define macro for this library.

#define BAUDRATE 9600   // Boudrate for serial connection,
                        
// Functions prototypes
void InitUART(void);    
void SerialSendByte(unsigned char); 
unsigned char SerialReceiveByte(void);
void SerialSendString(char*);

#endif      // End ifndef.