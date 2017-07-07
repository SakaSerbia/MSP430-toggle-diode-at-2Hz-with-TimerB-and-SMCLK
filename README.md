# Toggle diode at 2Hz with TimerB and SMCLK
A simple example, how to set up SMCLK and TimerB that diode turn on with 2Hz.

# Calculating parameters for Timer B
f_OUT = 2 Hz, 

f_SMCLK = 1048576Hz

=> **T_OUT = 525288**

T_OUT = 2 * T_CCR0 

=> **T_CCR0 = 262143** (TB0CCR0 = T_CCR0 - 1)

Value of T_CCR0 is too big and can not fit into registry. So we use **ID_3** and have this:

T_CCR0 = 262144 = 8 * 32768

=> **TB0CCR0 = 32768**

# Tested
Code was tested at MSP430F5438A.