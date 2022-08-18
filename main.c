/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Main file of the project.
 */

// PIC16F628A Configuration Bit Settings
#pragma config FOSC = INTOSCCLK     // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF           // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF          // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF          // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF          // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF            // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF            // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF             // Flash Program Memory Code Protection bit (Code protection off)

#include "library/Includes.h"       // Standard includes.
#include <xc.h>     // Standard compiler library.

#define LED PORTAbits.RA0       // Macro for led (PORTA RA0 pin). 

char response;      // Variable for store byte receive trough serial.

void main(void) {
    
    CMCON = 0b00000111;     // Disable comparators.      
    TRISA = 0b00000000;     // All pins of PORTA setting as output.
    
    InitUART();     // Initialize serial interface (UART), function of UART library.
    
	GIE  = 1;       // Enable global interrupts
    PEIE = 1;       // Enable Peripheral Interrupts

    SerialSendString("I'M ALIVE!!!\r\n");   // Send a text using a function of UART library.
    PORTAbits.RA0 = 1;      // Turn led on.
    
    while(1) {
        
        response = SerialReceiveByte();     // Store byte receive in serial, if have.
        if(response == 'D')     // If byte equals D
            LED = ~LED;     // Toggle led.
    }
    
    return;
}

