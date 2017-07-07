#include <msp430.h> 

/*
 * main.c
 */

int main(void) {

       WDTCTL = WDTPW | WDTHOLD;				// We're stopping watchdog timer

       // D1 4.3
       P4DIR |= BIT3;

       TB0CCTL0 = OUTMOD_4 | CCIE;				// We are using toggle outmode

	   //Code for ACLK = 32768 Hz
       //TB0CCR0 = 8191;
       //TB0CTL = TASSEL__ACLK | MC__UP;		// ACLK source, UP mode

       //Code for SMCLK = 1048576 Hz
       TB0CCR0 = 32768;
       TB0CTL = TASSEL__SMCLK | MC__UP | ID_3 ;	// MSCLK source, UP mode

       __enable_interrupt();

       while(1);
}

void __attribute__ ((interrupt(TIMER0_B0_VECTOR))) TB0CCR0ISR (void) {
	
       P4OUT ^= BIT3;
       TB0CCTL0 &= ~TAIFG;
}
