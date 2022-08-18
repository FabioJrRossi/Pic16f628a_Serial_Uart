/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Serial (UART) library implementation.
 */

#include "Includes.h"       // Include for use of the librarys.

// This function make configuration the serial peripherals and he's associated registers.
void InitUART(void) {
	TRISB2 = 0;                             // Set TX pin to output.
	TRISB1 = 1;                             // Set RX pin to input.
	SPBRG = ((_XTAL_FREQ/16)/BAUDRATE) - 1; // Setting the baud rate register.
	BRGH  = 1;                              // High baud rate selected (high speed).
	SYNC  = 0;                              // Asynchronous mode selected.
	SPEN  = 1;                              // Enable serial port pins (RX, TX).
	CREN  = 1;                              // Enabled continuous receive.
	TXIE  = 0;                              // Disable TX interrupts
	RCIE  = 1;                              // Enable RX interrupts
	TX9   = 0;                              // 8-bit transmission
	TXEN  = 0;                              // Disable transmitter for reset.
	TXEN  = 1;                              // Enable the transmitter
}

// Writes a character to the serial (Tx).
void SerialSendByte(unsigned char Byte) {  

	while(!TXIF);   // Wait to finish transmission.
	TXREG = Byte;   // Transfer byte to transmission register.
}

// Read a character from the serial (Rx).
unsigned char SerialReceiveByte(void) {   

	if(OERR){   // If over run error, then reset the receiver.
    
        CREN = 0;  
        CREN = 1;
    }
	
    while(!RCIF);  // Wait for transmission send a byte.
	
    return RCREG;  // Return byte in receive register.
}

// Send text (strings) to UART.
void SerialSendString(char* byte) {

	while(*byte)    // Wait all bytes of the string is send.
		SerialSendByte(*byte++);  // Call function for send one byte at a time.
}